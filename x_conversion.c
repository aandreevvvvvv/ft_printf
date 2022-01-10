/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:40:47 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/10 06:31:07 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
	Calculates length of number in hex
*/
int	hex_len(unsigned long long p)
{
	int	len;

	len = 1;
	while (p / 16)
	{
		++len;
		p /= 16;
	}
	return (len);
}

/*
	Prints number in hex, returns length
*/
int	ft_putnbr_hex(unsigned long long n, const char *digits)
{
	int		digit;
	int		len;

	len = 0;
	digit = n % 16;
	n /= 16;
	if (n)
		len += ft_putnbr_hex(n, digits);
	write(1, digits + digit, 1);
	++len;
	return (len);
}

/*
	Prints hex number with defined precision and prefix
	Returns length
*/
static int	puthex(t_args *args, unsigned int n)
{
	size_t	len;
	size_t	i;
	size_t	total_len;

	len = hex_len(n);
	i = 0;
	total_len = 0;
	if (args->precision == 0 && n == 0)
		return (0);
	if (args->hash && args->conversion == 'x' && n != 0)
		total_len += write(1, "0x", 2);
	else if (args->hash && args->conversion == 'X' && n != 0)
		total_len += write(1, "0X", 2);
	while ((int)(i + len) < args->precision)
		i += write(1, "0", 1);
	if (args->conversion == 'x')
		total_len += ft_putnbr_hex(n, "0123456789abcdef");
	else
		total_len += ft_putnbr_hex(n, "0123456789ABCDEF");
	return (total_len + i);
}

int	x_conversion(t_args *args, unsigned int n)
{
	size_t	len;
	size_t	i;

	len = hex_len(n);
	if ((int)len < args->precision)
		len = args->precision;
	if (args->hash && n != 0)
		len += 2;
	i = 0;
	if (args->minus)
	{
		i += puthex(args, n);
		while (i < args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (i + len < args->width && args->zero && args->precision == -1)
			i += write(1, "0", 1);
		while (i + len < args->width)
			i += write(1, " ", 1);
		i += puthex(args, n);
	}
	return (i);
}
