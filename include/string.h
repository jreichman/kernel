#ifndef __STRING_H
#define __STRING_H

#include <stdio.h>
#include <types.h>

extern inline void *memcpy(void *dest, const void *src, size_t len)
{
	char *tmp = (char *)dest;
	while(len > 0) {
		*(char *)dest++ = *(char *)src++;
		--len;
	}
	return tmp;
}

extern inline void *memmove(void *dest, const void *src, size_t len)
{
	void *tmp = dest;
	if(src < dest) {
		(char *)src += len;
		(char *)dest += len;

		while(len > 0) {
			*(char *)dest-- = *(char *)src--;
			--len;
		}
	} else {
		while(len > 0) {
			*(char *)dest++ = *(char *)src++;
			--len;
		}
	}
	return tmp;
}

extern inline void *memset(void *dest, int c, size_t len)
{
	void *tmp = dest;
	while(len > 0) {
		*(char *)dest++ = (unsigned char)c;
		--len;
	}
	return tmp;
}

extern inline int memcmp(const void *mem1, const void *mem2, size_t len)
{
	while(len > 0) {
		if(*(char *)mem1++ < *(char *)mem2++) return -1;
		if(*(char *)mem1++ > *(char *)mem2++) return 1;
		--len;
	}
	return 0;
}

extern inline const void *memchr(const void *mem1, int c, size_t len)
{
	while(len > 0) {
		if(*(const char *)mem1 == (unsigned char)c)
			return mem1;
		((const char *)mem1)++;
		--len;
	}
	return NULL;
}

extern inline const void *memrchr(const void *mem1, int c, size_t len)
{
	(const char *)mem1 += len;
	while(len > 0) {
		if(*(const char *)mem1 == (unsigned char)c)
			return mem1;
		((const char *)mem1)--;
		--len;
	}
	return NULL;
}

extern inline char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while(*tmp != 0) {
		*tmp++ = *src++;
	}

	return dest;
}

extern inline char *strncpy(char *dest, const char *src, size_t len)
{
	char *tmp = dest;
	while(len > 0 && *src != 0) {
		*tmp++ = *src;
		--len;
	}

	while(len > 0) {
		*tmp++ = 0;
		--len;
	}
	return dest;
}

extern inline char *strcat(char *dest, const char *src)
{
	char *tmp = dest;

	while(*tmp != 0) {
		++tmp;
	}
	while(*src != 0) {
		*tmp++ = *src++;
	}
	*tmp = 0;
	return dest;
}

extern inline char *strncat(char *dest, const char *src, size_t len)
{
	return NULL;
}

extern inline int strcmp(const char *str1, const char *str2)
{
	while(*str1 != 0) {
		if(*str1 < *str2) return -1;
		if(*str1 > *str2) return 1;
		++str1;
		++str2;
	}
	if(*str1 < *str2) return -1;
	if(*str1 > *str2) return 1;
	return 0;
}

extern inline int strncmp(const char *str1, const char *str2, size_t len)
{
	return 0;
}

extern inline char *strdup(const char *str)
{
	return NULL;
}

extern inline char *strndup(const char *str, size_t len)
{
	return NULL;
}

extern inline char *strchr(const char *str, int c)
{
	return NULL;
}

extern inline char *strrchr(const char *str, int c)
{
	return NULL;
}

extern inline size_t strcspn(const char *string, const char *reject)
{
	return 0;
}

extern inline size_t strspn(const char *string, const char *accept)
{
	return 0;
}

extern inline char *strpbrk(const char *string, const char *accept)
{
	return NULL;
}

extern inline char *strstr(const char *string, const char *search)
{
	return NULL;
}

extern inline size_t strlen(const char *string)
{
	size_t len = 0;
	while(*string != 0) {
		++len;
		++string;
	}
	return len;
}

extern inline size_t strnlen(const char *string, size_t len)
{
	return 0;
}

extern inline char *strerror(int err)
{
	return "undefined";
}

extern inline void bcopy(const void *src, void *dest, size_t len)
{
}

extern inline void bzero(void *mem, size_t len)
{
}

extern inline int bcmp(const void *mem1, const void *mem2, size_t len)
{
	return 0;
}

extern inline int strcasecmp(const char *str1, const char *str2)
{
	return 0;
}

extern inline int strncasecmp(const char *str1, const char *str2, size_t len)
{
	return 0;
}

#endif /* __STRING_H */
