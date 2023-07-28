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
 * printi - prints int
 * @x: intiger
 */

void printi(int x)
{
	if (x < 0)
	{
		_putchar('-');
		x = -1 * x;
	}
	if (x / 10 != 0)
		printi(x / 10);
	
	_putchar('0' + x % 10);
}

/**
 * counti - counts int length
 * @x: int
 *
 * Return: int length
 */

int counti(int x)
{
	int i = 0;

	if (x < 0)
	{
		x = -1 * x;
		++i;
	}
	while (x > 0)
	{
		++i;
		x = x / 10;
	}
	return (i);
}

/**
 * _printf - custom made printf function
 * @format: character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, n, x, count = 0;
	char *str;
	va_list arg;

	if (format == NULL)
		return (-1);

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
				case 'i':
					x = va_arg(arg, int);
					printi(x);
					count += counti(x);
					break;
				case 'd':
					x = va_arg(arg, int);
					printi(x);
					count += counti(x);
					break;
				case 'c':
					_putchar(va_arg(arg, int));
					++count;
					break;
				case 's':
					str = va_arg(arg, char *);
					if (str != NULL)
					{
						prints(str, strlen(str));
						count += strlen(str);
					}
					else if (str == NULL)
					{
						prints("(null)", 6);
						count += 6;
					}
					break;
				case '%':
					_putchar('%');
					++count;
					break;
				default:
					_putchar(format[i]);
					++count;
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

