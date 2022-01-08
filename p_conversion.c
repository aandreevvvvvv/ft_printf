/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:42:29 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/09 02:14:56 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	hex_len(unsigned long long p)
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

int	p_conversion(t_args *args, void *p)
{
	size_t	len;
	size_t	i;

	len = 2 + hex_len((unsigned long long)p);
	i = 0;
	if (args->minus)
	{
		write(1, "0x", 2);
		ft_puthex((unsigned long long)p, "0123456789abcdef");
		i += len;
		while (args->width && i < (size_t)args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (args->width && i < (size_t)args->width + len)
			i += write(1, " ", 1);
		write(1, "0x", 2);
		ft_puthex((unsigned long long)p, "0123456789abcdef");
		i += len;
	}
	return (i);
}
