/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:34 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/20 15:15:44 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int ft_putchar (char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putnbr(long long int nbr, int base)
{
	static size_t nbr_print;
	size_t sign;
	const char basestr[16] = "0123456789abcdef";

	if (base == 10)
		nbr = (int)nbr;
	nbr_print = 0;
	sign = 0;
	if (nbr == -2147483648 && base == 10)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		ft_putchar ('-');
		nbr = nbr * -1;
		sign = 1;
	}
	if(nbr > base - 1) 
	{
		ft_putnbr(nbr / base, base);
	}
	nbr_print += ft_putchar((basestr[nbr % base]));
	return (nbr_print + sign);
}

size_t ft_putstr(char *str)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str && str[i])
	{
		ft_putchar(str[i]);		
		size += 1;
		i++;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	size_t nbr_printed;
	size_t i;
	va_list input;

	nbr_printed = 0;
	i = 0;
	va_start(input, str);
	while(str && str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
			{
				nbr_printed += ft_putnbr(va_arg (input, long long int), 10);
			}
			if (str[i] == 's')
			{
				nbr_printed += ft_putstr(va_arg(input, char *));
			}
			if (str[i] == 'x')
			{
				nbr_printed += ft_putnbr(va_arg (input, long long int), 16);
			}		
		}
		else
		{
			nbr_printed += ft_putchar(str[i]);		
		}
		i++;
	}
	va_end(input);
	return ((int)nbr_printed);
}

int main(int argc, char *argv[])
{
	int nbr3;
	int res;
	char *str = argv[2];

	nbr3 = atoi(argv[1]);
	res = 0;

	res = ft_printf("%x %s %s  %s",nbr3, str, str, str);
	printf("%d\n", res);
	res = printf("%x %s %s  %s",nbr3, str, str, str);
	printf("%d\n", res);
	
	return (0);
}