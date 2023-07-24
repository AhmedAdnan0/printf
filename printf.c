#include "main.h"

/**
 * prints - print a char string
 * @str: string to be printed
 * @n: str length
 */

void prints(char *str, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		_putchar(str[i]);
}

/**
 * _printf - custom made printf function
 * @format: character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, n, count = 0;
	char *str;
	va_list arg;

	n = strlen(format);
	va_start(arg, format);
	for (i = 0; i < n; ++i)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			++count;
		}
		else if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					++i;
					_putchar(va_arg(arg, int));
					++count;
					break;
				case 's':
					++i;
					str = va_arg(arg, char *);
					prints(str, strlen(str));
					count += strlen(str);
					break;
				default:
					_putchar('%');
			}
		}
	}
	va_end(arg);
	return (count);
}
