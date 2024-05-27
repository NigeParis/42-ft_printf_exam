/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:18:40 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/27 10:20:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int nb_printed;
	int i;

	nb_printed = 0;
	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str && str[i])
	{
		nb_printed += ft_putchar(str[i]);
		i++;
	}
	return (nb_printed);
}

int	ft_putnbr(long long int nbr, int base)
{
	const char basestr[16] = "0123456789abcdef";
	static int nb_printed;
	int sign;

	nb_printed = 0;
	sign = 0;
	if (base == 10)	
		nbr = (int)nbr;		
	else
		nbr = (unsigned int)nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
		sign = 1;
	}
	if (nbr > base - 1)
	{
		ft_putnbr((nbr / base), base);	
	}
	nb_printed += ft_putchar((basestr[nbr % base]));
	return (nb_printed + sign);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int nb_printed;
	int	i;

	nb_printed = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str && str[i])
	{
		if (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] && str[i] == 's')
				nb_printed += ft_putstr(va_arg(args, char *));
			if ((str[i] && str[i] == 'd') || (str && str[i] == 'i'))
				nb_printed += ft_putnbr(va_arg(args, long long int), 10);
			if (str[i] && str[i] == 'x')
				nb_printed += ft_putnbr(va_arg(args, long long int), 16);
			if (str[i] && str[i] == '%')
				nb_printed += ft_putchar('%');
		}
		else
			nb_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (nb_printed);	
}

// int main(void)
// {
// 	char *str = "helloworld";
// 	int	nb_printed;
// 	int nbr1 = -2147483648;
// 	int nbr2 = -1;
	
// 	nb_printed = 0;
// 	nb_printed = ft_printf("string %s %d %d %d%x%x%x%%", str, nbr1, nbr2, nbr1, nbr2, nbr1, nbr2);
// 	printf("\nnb_printed %d\n", nb_printed);
// 	   nb_printed = printf("string %s %d %d %d%x%x%x%%", str, nbr1, nbr2, nbr1, nbr2, nbr1, nbr2);
// 	printf("\nnb_printed %d\n", nb_printed);
// 	nb_printed = ft_printf(NULL);
// 	printf("\nnb_printed %d\n", nb_printed);
// 	   nb_printed = printf(NULL);
// 	printf("\nnb_printed %d\n", nb_printed);
// 	return (0);
// }