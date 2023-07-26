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
		if (format[i] == '\\')
		{
			++i;
			switch (format[i])
			{
				case 'n':
					_putchar('\n');
					++count;
					break;
				case '\\':
					_putchar('\\');
					++count;
 					break;
				case '\"':
					_putchar('\"');
					break;
			}
		}
		else if (format[i] == '%')
		{
			++i;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(arg, int));
					++count;
					break;
				case 's':
					str = va_arg(arg, char *);
					prints(str, strlen(str));
					count += strlen(str);
					break;
				case '%':
					_putchar('%');
					++count;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			++count;
		}
	}
	va_end(arg);
	return (count);
}

