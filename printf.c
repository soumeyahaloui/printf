#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	const char *ptr;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			printed_chars++;
		}
		else
		{
			ptr++;

			if (*ptr == '\0')
				return (-1);

			switch (*ptr)
			{
				case 'c':
					printed_chars += print_char(va_arg(args, int));
					break;
				case 's':
					printed_chars += print_string(va_arg(args, char *));
					break;
				case '%':
					printed_chars += print_char('%');
					break;
				default:
					write(1, "%", 1);
					write(1, ptr, 1);
					printed_chars += 2;
					break;
			}
		}
	}

	va_end(args);

	return (printed_chars);
}
