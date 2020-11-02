#ifndef __STDLIB_H
#define __STDLIB_H

#include <stdio.h>

#undef EXIT_FAILURE
#define EXIT_FAILURE	1

#undef EXIT_SUCCESS
#define EXIT_SUCCESS	0


#undef RAND_MAX
#define RAND_MAX	255

/* probably should not be here */
#define ARRAYSIZE(x)	(sizeof((x))/sizeof((x)[0]))


extern char **environ;

char *itoa(long int num);

char *__itoa_buffer(char * buffer, long int num, unsigned int base);

double strtod(const char *string, char ** endptr, int base);

float strtof(const char *string, char ** endptr, int base);

long double strtold(const char *string, char ** endptr, int base);

long strtol(const char *string, char ** endptr, int base);

unsigned long strtoul(const char *string, char ** endptr, int base);

extern inline double atof(const char *string)
{
	return strtof(string, (char **)NULL, 10);
}

extern inline int atoi(const char *string)
{
	return strtol(string, (char **)NULL, 10);
}

extern inline long int atol(const char *string)
{
	return strtol(string, (char **)NULL, 10);
}

void *malloc(size_t len);

void *calloc(size_t num, size_t len);

void *realloc(void *ptr, size_t nlen);

void free(void *ptr);

char *getenv(const char *name);

int putenv(const char *string);

int setenv(const char *name, const char *value, int replace);

int unsetenv(const char *name);

int clearenv(void);

/*

void *bsearch(const void *key, const void *base, size_t num, size_t len, COMPARE_FUNCTION comp);

void *qsort(const void *base, size_t num, size_t len, COMPARE_FUNCTION comp);

*/

int abs(int val);

long int labs(long int val);

#endif /*__STDLIB_H*/
