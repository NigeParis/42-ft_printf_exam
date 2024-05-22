/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:28:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/22 10:51:36 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int size;
	int i;

	i = 0;
	size = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str && str[i])
	{
		size += ft_putchar(str[i]);
		i++;
	}
	return (size);
}

int	ft_putnbr(long int nbr, int base)
{
	const char basestr[16] = "0123456789abcdef";
	static int size;
	int neg;

	size = 0;
	neg = 0;
	if (base < 2)
		return (0);
	if (base == 10)
		nbr = (int)nbr;
	if (nbr < 0)
	{
		size += ft_putchar('-');
		nbr *= -1;
		neg = 1;
	}
	if (nbr > base -1)
	{
		ft_putnbr((nbr / base), base);
	}
	size += ft_putchar((basestr[nbr % base]));
	return (size + neg);
}



int	ft_printf(const char *str, ...)
{
	va_list input;
	int nbr_printed;
	int i;

	nbr_printed = 0;
	i = 0;
	va_start(input, str);
	while (str && str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd' || str[i] == 'i')
			{
				nbr_printed += ft_putnbr(va_arg(input, long int), 10);	
			}
			if (str[i] == 'x')
			{
				nbr_printed += ft_putnbr(va_arg(input, long int), 16);	
			}
			if (str[i] == 's')
			{
				nbr_printed += ft_putstr(va_arg(input, char *));	
			}	
		}
		else
		{
			nbr_printed += ft_putchar(str[i]);	
		}
		i++;	
	}
	va_end(input);
	return (nbr_printed);
}


int main(int argc, char *argv[])
{

	int nbr;
	int res = 0;
	
	nbr = (int)atoi(argv[argc -1]);
	res = ft_printf("\nnbr %d, %s %x \n", nbr, argv[2],  nbr);
	ft_putnbr(res, 10);
	res = printf("\nnbr %d, %s %x \n", nbr,  argv[2], nbr);
	ft_putnbr(res, 10);
	return (0);
}