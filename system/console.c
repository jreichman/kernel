#include <string.h>
#include <stdlib.h>
#include <asm/io.h>
#include <kernel/console.h>

/* terminal size */
static int column_num = 80 , row_num = 25;

/* current position */
static uint32 row = 0, column = 0;


/* Console addresses */
static volatile uint16 *base = (uint16 *)0xB8000;
static volatile uint16 *end = (uint16 *)0xB8000 + (80 * 25);


static void move_cursor(uint32 r, uint32 c)
{
	unsigned short int pos = (r * column_num) + c;

	row = r;
	column = c;

	outb(0x3D4, 0xF);
	outb(0x3D5, (uchar) (pos & 0xFF));
	outb(0x3D4, 0xE);
	outb(0x3D5, (uchar) ((pos >> 8) & 0xFF));
}

static void clear(void)
{
	uint16 fill = 7 << 8;
	volatile uint16 *it = base;

	while(it != end) {
		*it = fill;
		++it;
	}
	move_cursor(0,0);
}

static void scroll_up(int lines)
{
	volatile uint16 *it;
	uint16 fill = 7 << 8;

	if(lines == 0) return;

	if(lines >= row_num) {
		clear();
		return;
	}

	memmove(base, base + (column_num * lines),
		((row_num - lines) * column_num)*sizeof(uint16));
	it = base + (row_num - lines) * column_num;
	while(it != end) {
		*it = fill;
		++it;
	}
	--row;
	if(row < 0) row = 0;
	move_cursor(row,column);
}

int console_init(void)
{
	clear();
	return 0;
}

int console_write(char c)
{
	switch(c) {
		case '\n':
			++row;
		case '\r':
			column = 0;
			break;
		case '\f':
			clear();
			break;
		case '\t':
			c = ' ';
		default:
			*(base + (column + row * column_num)) = c | 7 << 8;
			++column;
	}
	if(column >= column_num) {
		column = 0;
		++row;
	}
	if(row >= row_num) {
		scroll_up((row - row_num) + 1);
	}
	move_cursor(row, column);
	return c;
}

int console_read(void)
{
	return -1;
}

