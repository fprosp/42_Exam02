/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$
*/



#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/*int ft_printf2 (char *str, ...)
{
	int c;
	va_list arg;
	int i;

	i =-1;
	c = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i]== '%')
		{
			i++;
			int j;
			j=0;
			if (str[i]== 's')
			{
				char *s;
				s = va_arg(arg, char *);
				if (!s)
					s = "(NULL)";
				while (s[j])
				{
					write(1,&s[j],1);
					j++;
				}
				c=j;
			}
			if (str[i]== 'd' || str[i]== 'x')
			{
				int base;
				if (str[i]== 'd')
				{
					base = 10;
					j = va_arg(arg, int);
					if (j<0)
					{
						write (1,"-",1);
						c++;
					}
					j=(unsigned long long int)j;
				}
				else 
				{
					base = 16;
					j = va_arg(arg, unsigned long long int);
				}
				int k;
				k=0;
				while (j!='\0')
				{
					k *=base;
					k += j%base;
					j = j/base;
				}
				while (k != '\0')
					{
						write(1,&"0123456789abcdef"[k% base], 1);
						k = k/base;
					}
					c++;
				
			}
		}
		else
		write (1,&str[i],1);
	}
	va_end (arg);
	return(c);
}*/

/*int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(unsigned int n, int base)
{
	int	i;
	char *alphab;

	alphab = "0123456789abcdef";
	i = 0;
	if (n > (unsigned int)base)
		i += ft_putnbr(n / base, base);
	return (i + write(1, &alphab[n % base], 1));
}

int	ft_putint(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	count += ft_putnbr(n, 10);
	return (count);
}*/

int ft_putchar(char c)
{
	int i;

	i = 0;
	return (i + write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		i += write(1, &str[i], 1);
	}
	return (i);
}

int ft_putnbr(unsigned int n, unsigned int base)
{
	int i;
	char *alphab;

	i = 0;
	alphab = "0123456789abcdef";
	if (n > base)
	{
		i += ft_putnbr(n / base, base);
	}
	return (i + write(1, &alphab[n % base], 1));
}

int ft_putint(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = n * -1;
	}
	i += ft_putnbr((unsigned int) n, 10);
	return (i);
}

int ft_printf(char *str, ...)
{
	int count;
	int i;
	va_list args;

	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				count += ft_putstr(va_arg(args, char *));
			}
			else if (str[i] == 'd')
			{
				count += ft_putint(va_arg(args, int));
			}
			else if (str[i] == 'x')
			{
				count += ft_putnbr(va_arg(args, unsigned int), 16);
			}
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(args);
	return (count);
}

int main ()
{
	int i;

	i=14314;
	printf("COUNT: %d\n", ft_printf("T%s\n", "ciao"));
	printf("COUNT: %d\n", ft_printf("Il numero è: %d\n", i));
	printf("COUNT: %d\n", ft_printf("HEX %x\n", i));
	printf("COUNT: %d\n", printf("T%s\n", "ciao"));
	printf("COUNT: %d\n", printf("Il numero è: %d\n", i));
	printf("COUNT: %d\n", printf("HEX %x\n", i));
	return(0);
}