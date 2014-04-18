#include "unistd.h"

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
			write(1, s++, 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(size_t n, size_t base)
{
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'A');
	}
}

void	ft_putmem(size_t n)
{
	ft_putstr("0x");
	ft_putnbr_base(n, 16);
}