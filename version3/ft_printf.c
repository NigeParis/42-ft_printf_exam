/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:57:33 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/22 10:37:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int len;
	
	len = 0;
	if (!str)
		return (0);
	while (str && str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr(long long int nbr, int base)
{
	const char basestr[16] = "0123456789abcdef";
	static int nb_printed;
	int sign = 0;

	nb_printed = 0;

	if (base < 2)
		return (0);
	if (base == 10)
		nbr = (int)nbr;
	if (nbr < 0)
	{
		if (base == 10)
		{
			nb_printed += ft_putchar('-');
			if (nbr < -9)
				sign = 1;
		}
		nbr = nbr * -1;
	}
	if (nbr > base - 1)
	{
		ft_putnbr(nbr / base, base);
	}
	nb_printed += ft_putchar(basestr[nbr % base]);

	return (nb_printed + sign);
}

int	ft_printf(const char *str, ...)
{
	va_list input;
	int nb_printed;
	int i;

	nb_printed = 0;
	i = 0;
	va_start(input, str);

	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				nb_printed += ft_putstr(va_arg(input, char *));
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				nb_printed += ft_putnbr(va_arg(input, long int), 10);	
			}
			if (str[i] == 'x')
			{
				nb_printed += ft_putnbr(va_arg(input, long int), 16);	
			}
			if (str[i] == '%')
			{
				nb_printed += ft_putchar('%');	
			}
			
		}
		else
		{
			nb_printed += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(input);
	return (nb_printed);
}




int	main(int argc, char *argv[])
{
	int	nb_printed = 0;
	char str[] = "decimal:";
	int nb = 0;
	int nbr = atoi(argv[argc-1]);

	nb = ft_printf("%x%d%%", nbr, nbr);	
	printf("\nnb_printed :%d\n",nb);

	   nb = printf("%x%d%%", nbr, nbr);	
	printf("\nnb_printed :%d\n",nb);
	return (0);
}