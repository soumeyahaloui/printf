#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string with zero or more directives
 *
 * Returns the count of printed characters to stdout (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += _putchar('%');
			else if (format[i] == 'c')
				count += _print_char(args);
			else if (format[i] == 's')
				count += _print_string(args);
			else
				count += _putchar('%') + _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * _print_char - prints a character
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int _print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * _print_string - prints a string
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	return (_puts(str));
}

/**
 * _puts - prints a string to stdout
 * @str: string to print
 *
 * Return: number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str && str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
