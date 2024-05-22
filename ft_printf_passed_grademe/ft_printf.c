/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:12:02 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/22 17:25:48 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int len;
	int nb_print;

	len = 0;
	nb_print = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[len])
	{
		nb_print += ft_putchar(str[len]);
		len++;
	}
	return (nb_print);
}

int	ft_putnbr(long int nbr, int base)
{
	const char basestr[16] = "0123456789abcdef";
	static int nb_print;
	int sign = 0;

	nb_print = 0;
	if (base < 2)
		return (0);
	if (base == 10)
		nbr = (int)nbr;
	if (nbr < 0)
	{
		if (base == 10)
		{
			nb_print += ft_putchar('-');
			if (nbr < -9)
				sign = 1;
		}
		nbr = nbr * -1;
	}
	if (nbr > base -1)
	{
		ft_putnbr((nbr / base), base);
	}
	nb_print += ft_putchar(basestr[nbr % base]);
	return (nb_print + sign);
}



int	ft_printf(const char *str, ...)
{
	va_list input;
	int nb_print = 0;
	int i = 0;

	va_start(input, str);

	while (str && str[i])
	{
		if (str[i] && str[i] == '%')
		{
			i++;
			if ((str[i] && str[i] == 'd') || (str[i] && str[i] == 'i'))
			{
				nb_print += ft_putnbr(va_arg(input, long int), 10);
			}	
			if (str[i] && str[i] == 's')
			{
				nb_print += ft_putstr(va_arg(input, char *));
			}	
			if (str[i] && str[i] == 'x')
			{
				nb_print += ft_putnbr(va_arg(input, long int), 16);
			}
			if (str[i] && str[i] == '%')
			{
				nb_print += ft_putchar('%');
			}		
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

