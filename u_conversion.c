/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:36:29 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/10 06:49:38 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
	Calculates length of number in dec
*/
static int	dec_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		++len;
		n /= 16;
	}
	return (len);
}

/*
	Prints number in dec, returns length
*/
static int	ft_putnbr_dec(unsigned long long n)
{
	int		digit;
	int		len;

	len = 0;
	digit = n % 10;
	n /= 10;
	if (n)
		len += ft_putnbr_dec(n);
	digit += '0';
	write(1, &digit, 1);
	++len;
	return (len);
}

/*
	Prints dec number with defined precision
	Returns length
*/
static int	putdec(t_args *args, unsigned int n)
{
	size_t	len;
	size_t	i;

	len = dec_len(n);
	i = 0;
	if (args->precision == 0 && n == 0)
		return (0);
	while ((int)(i + len) < args->precision)
		i += write(1, "0", 1);
	if (args->conversion == 'x')
		i += ft_putnbr_dec(n);
	else
		i += ft_putnbr_dec(n);
	return (i);
}

int	u_conversion(t_args *args, unsigned int n)
{
	size_t	len;
	size_t	i;

	len = dec_len(n);
	if ((int)len < args->precision)
		len = args->precision;
	if (args->precision == 0 && n == 0)
		len = 0;
	i = 0;
	if (args->minus)
	{
		i += putdec(args, n);
		while (i < args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (i + len < args->width && args->zero && args->precision == -1)
			i += write(1, "0", 1);
		while (i + len < args->width)
			i += write(1, " ", 1);
		i += putdec(args, n);
	}
	return (i);
}
