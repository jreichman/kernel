#ifndef __STDIO_H
#define __STDIO_H

#include <stdarg.h>
#include <kernel/console.h>

#undef EOF
#define EOF	(-1)

struct __printf_write_str {
	int (*write)(struct __printf_write_str *, const char *);
	void *arg;
	size_t len;
};


int __parse_printf_fmt(struct __printf_write_str *handler,
					const char * format, va_list list);

int printf(const char * format, ...);

int vprintf(const char * format, va_list arg);

int vsprintf(char * dest, const char * format, va_list arg);

int snprintf(char * dest, size_t len, const char * format, ...);

int vsnprintf(char * dest, size_t len, const char * format, va_list arg);

int vasprintf(char ** dest, const char * format, va_list arg);

int asprintf(char ** dest, const char * format, ...);

int sprintf(char * buf, const char * format, ...);

int scanf(const char * format, ...);

int sscanf(const char * str, const char * format, ...);

extern inline int getchar(void)
{
	return console_read();
}

extern inline int putchar(int c)
{
	return console_write(c);
}

extern inline int puts(const char *string)
{
	int len = 0;
	while(*string) {
		putchar(*string);
		++string;
		++len;
	}
	return len;
}

void perror(const char * str);

#endif /*__STDIO_H*/
