#include <unistd.h>
#include <stdarg.h>

void	put_string(char *s, int *len)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		while (*s)
		{
			write(1, s, 1);
			*len += 1;
			s++;
		}
	}
}

void	put_nbr(long long int num, int base, int *len)
{
	char	*hexa = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		*len += 1;
	}
	if (num / base > 0)
		put_nbr(num / base, base, len);
	write(1, &hexa[num % base], 1);
	*len += 1;
}

int	ft_printf(const char *format, ...)
{
	int	len = 0;
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(args, char *), &len);
			if (*format == 'd')
				put_nbr((long long int)va_arg(args, int), 10, &len);
			if (*format == 'x')
				put_nbr((long long int)va_arg(args, unsigned int), 16, &len);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
int	main(void)
{
	char	*s = "hello";
	int	i = 15;
	printf("%d",	ft_printf("hikaru%s%d%x", s, i, i));
	return (0);
}