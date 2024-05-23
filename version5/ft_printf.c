/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:40:32 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/23 15:02:56 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int nb_print;
	int i;

	i = 0;
	nb_print = 0;
	
	if(!str)
		return (ft_putstr("(null)"));
	while (str && str[i])
	{
		nb_print += ft_putchar(str[i]);
		i++;
	}
	return (nb_print);
}

int	ft_putnbr(long long int nbr, int base)
{
	const char basestr[16] = "0123456789abcdef";
	//static int nb_print = 0;
	static int nb_print;
	int sign = 0; 
	int ret;

	nb_print = 0;
	if (base < 2)
		return (0);
	if (base == 10)
		nbr = (int)nbr;
	if (base == 16)
		nbr = (unsigned int)nbr;
	if(nbr < 0)
	{
		if (base == 10)
		{
			nb_print += ft_putchar('-');
			if (nbr < -9)
				sign = 1;
		}
		nbr = nbr * -1;	
	}
	if(nbr > (base -1))
	{
		ft_putnbr((nbr / base), base);
	}
	nb_print += ft_putchar((basestr[nbr % base]));
	ret = nb_print + sign;
	return (ret);
}


int	ft_printf(const char *str, ...)
{
	va_list input;
	int nb_print;
	int i;

	i = 0;
	nb_print = 0;
	va_start(input, str);
	if (!str)
		return(-1);
	while (str && str[i])
	{
		if (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] && str[i] == 's')
				nb_print += ft_putstr(va_arg(input, char *));
			if ((str[i] && str[i] == 'd') || (str[i] && str[i] == 'i'))
				nb_print += ft_putnbr(va_arg(input, int), 10);
		    if (str[i] && str[i] == 'x')
				nb_print += ft_putnbr(va_arg(input, long int), 16);
			if (str[i] && str[i] == '%')
				nb_print += ft_putchar('%');
		}
		else
		{
			nb_print += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(input);
	return (nb_print);
}

int main(void)
{
	int nb;
	//char str[] = "hello";
	int nbr = 42;
	int nbr2 = -1;
	int nbr4 = -2;

	nb = 0;

	nb = ft_printf("%d %x %x %d %x %x %x %x %x %%", nbr2, nbr, nbr2, nbr, nbr, nbr2, nbr2, nbr, nbr4);
	printf("\nnb printed :%d\n", nb);

	   nb = printf("%d %x %x %d %x %x %x %x %x %%", nbr2, nbr, nbr2, nbr, nbr, nbr2, nbr2, nbr, nbr4);
	printf("\nnb printed :%d\n", nb);
	
	nb = ft_printf("%x %x %x %d %x%%", nbr2, nbr2, nbr, nbr, nbr4);
	printf("\nnb printed :%d\n", nb);

	   nb = printf("%x %x %x %d %x%%", nbr2, nbr2, nbr, nbr, nbr4);
	printf("\nnb printed :%d\n", nb);

	
	nb = ft_printf(NULL);
	printf("\nnb printed :%d\n", nb);

	   nb = printf(NULL);
	printf("\nnb printed :%d\n", nb);

	return (0);	
}