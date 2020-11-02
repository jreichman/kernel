#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int __parse_printf_fmt(struct __printf_write_str *handler,
					 const char * format, va_list list)
{
	const char *iter = format;
	int special = 0;
	int ret;
	int total = 0;
	char buffer[64];
	char *str = NULL;
	
	while(*iter != 0) {
		ret = 0;
		if(special) {
			special = 0;
			switch(*iter) {
				case '%':
					buffer[0] = '%';
					buffer[0] = 0;
					ret = handler->write(handler, buffer);
					break;
				case 'c':
					buffer[0] = va_arg(list, char);
					buffer[1] = 0;
					ret = handler->write(handler, buffer);
					break;
				case 's':
					str = va_arg(list, char *);
					if(str == NULL) {
						strcpy(buffer, "(null)");
						str = buffer;
					}
					ret = handler->write(handler, str);
					str = NULL;
					break;
				case 'x':
					__itoa_buffer(buffer, va_arg(list, int), 16);
					ret = handler->write(handler, buffer);
					break;
				case 't':
					__itoa_buffer(buffer, va_arg(list, int), 2);
					ret = handler->write(handler, buffer);
					break;
				case 'd':
				case 'i':
					__itoa_buffer(buffer, va_arg(list, int), 10);
					ret = handler->write(handler, buffer);
					break;
			}
		} else {
			switch(*iter) {
				case '%':
					special = 1;
					break;
				default:
					buffer[0] = *iter;
					buffer[1] = 0;
					ret = handler->write(handler, buffer);
			}
		}
		if(ret < 0) return total;
		total += ret;
		++iter;
	}
	return total;
}

