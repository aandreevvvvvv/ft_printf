/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:40:47 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/09 03:38:02 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

int	ft_puthex(unsigned long long n, const char *digits)
{
	int		digit;
	int		len;

	len += 0;
	digit = n % 16;
	n /= 16;
	if (n)
		len += ft_puthex(n, digits, 0);
	write(1, digits + digit, 1);
	++len;
	return (len);
}

int	x_conversion(t_args *args, unsigned int n)
{
	size_t	len;
	size_t	i;

	len = hex_len(n);
	i = 0;
	if (args->minus && !args->zero)
	{
		while ((int)(i + len) < args->precision)
			i += write(1, "0", 1);
		if (!(args->precision == 0 && n == 0))
			i += ft_puthex((unsigned long long)n, "0123456789abcdef");
		while (args->width && i < (size_t)args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (args->width && i + len < (size_t)args->width)
			i += write(1, " ", 1);
		while ((int)(i + len) < args->precision)
			i += write(1, "0", 1);
		if (!(args->precision == 0 && n == 0))
			i += ft_puthex((unsigned long long)n, "0123456789abcdef");
	}
	return (i);
}

int	bigx_conversion(t_args *args, unsigned int n)
{
	size_t	len;
	size_t	i;

	len = hex_len(n);
	i = 0;
	if (args->minus)
	{
		while ((int)(i + len) < args->precision)
			i += write(1, "0", 1);
		if (!(args->precision == 0 && n == 0))
			i += ft_puthex((unsigned long long)n, "0123456789ABCDEF");
		while (args->width && i < (size_t)args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (args->width && i + len < (size_t)args->width)
			i += write(1, " ", 1);
		while ((int)(i + len) < args->precision)
			i += write(1, "0", 1);
		if (!(args->precision == 0 && n == 0))
			i += ft_puthex((unsigned long long)n, "0123456789ABCDEF");
	}
	return (i);
}
