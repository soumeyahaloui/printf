/* main.h */

#ifndef MAIN_H
#define MAIN_H

/* Function prototypes */
int _printf(const char *format, ...);

#endif /* MAIN_H */


/* _printf.c */

#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j, len = 0;
	char buffer[1024];
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[len++] = format[i];
			continue;
		}

		i++;

		switch (format[i])
		{
			case 'c':
				buffer[len++] = va_arg(args, int);
				break;
			case 's':
				for (j = 0; format[j]; j++)
					buffer[len++] = va_arg(args, int);
				break;
			default:
				buffer[len++] = '%';
				buffer[len++] = format[i];
				break;
		}
	}

	va_end(args);

	write(1, buffer, len);

	return (len);
}
