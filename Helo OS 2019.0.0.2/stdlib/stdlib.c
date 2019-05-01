#include "../apilib.h"
#include "../stdlib.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define MAX_BUF 1024

// ctype

int isspace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

int isdigit(char c)
{
	return '0' <= c && c <= '9';
}

// string

int strchr(const char *str, char c)
{
	for (; *str; str++)
		if (*str == c)
			return 1;
	return 0;
}

// stdio

int putchar(int c)
{
	api_putchar(c);
	return c;
}

int getchar()
{
	int c = api_getkey(1);
	putchar(c);
	return c;
}

int puts(const char *str)
{
	api_putstr0(str);
	putchar('\n');
	return strlen(str);
}

char *gets(char *str)
{
	char *ptr = str;
	while (1) {
		char c = getchar();
		if (c == '\r' || c == '\n') {
			*ptr = '\0';
			return str;
		} else {
			*ptr = c;
			ptr++;
		}
	}
}

int scanf(const char *format, ...)
{
    int count = 0, base;
    char *temp, buffer[MAX_BUF];
    va_list ap;
    va_start(ap, format);
    while (*format) {
		while (isspace(*format))
		    format++;
		if (*format == '%') {
		    format++;
		    for (; *format; format++)
				if (strchr("dibouxcsefg%", *format))
				    break;
		    if (*format == 's') {
		    	char c = getchar();
				while (isspace(c))
					c = getchar();
				temp = va_arg(ap, char *);
				while (!isspace(c)) {
					*temp = c;
					temp++;
					c = getchar();
				}
				*temp = '\0';
		    } else if (*format == 'c') {
		    	char c = getchar();
				while (isspace(c))
					c = getchar();
				temp = va_arg(ap, char *);
				*temp = c;
		    } else if (strchr("dobxu", *format)) {
		    	char c = getchar();
				while (isspace(c))
					c = getchar();
				if (*format == 'd' || *format == 'u')
				    base = 10;
				else if (*format == 'x')
				    base = 16;
				else if (*format == 'o')
				    base = 8;
				else if (*format == 'b')
				    base = 2;
				temp = buffer;
				while (!isspace(c)) {
					*temp = c;
					temp++;
					c = getchar();
				}
				*temp = '\0';
				int *numptr = va_arg(ap, int *);
				*numptr = strtol(buffer, NULL, base);
		    }
			count++;
		    format++;
		} else if (*format) {
			char c = getchar();
		    while (isspace(c)) 
				c = getchar();
		    if (*format != c)
				break;
		    else 
		    	format++;
		}
	}
	va_end(ap);
    return (count);
}

int printf(const char *format, ...)
{
	va_list ap;
	char s[MAX_BUF];
	int i;
	va_start(ap, format);
	i = vsprintf(s, format, ap);
	api_putstr0(s);
	va_end(ap);
	return i;
}

// stdlib

void exit(int status)
{
	api_end();
}

void *malloc(int size)
{
	char *p = api_malloc(size + 16);
	if (p != 0) {
		*((int *) p) = size;
		p += 16;
	}
	return p;
}

void free(void *p)
{
	char *q = p;
	int size;
	if (q != 0) {
		q -= 16;
		size = *((int *) q);
		api_free(q, size + 16);
	}
	return;
}
