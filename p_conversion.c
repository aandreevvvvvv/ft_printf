/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:42:29 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/10 06:10:20 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	p_conversion(t_args *args, void *p)
{
	size_t	len;
	size_t	i;

	len = 2 + hex_len((unsigned long long)p);
	i = 0;
	if (args->minus)
	{
		i += write(1, "0x", 2);
		i += ft_putnbr_hex((unsigned long long)p, "0123456789abcdef");
		while (args->width && i < (size_t)args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (args->width && i + len < (size_t)args->width)
			i += write(1, " ", 1);
		i += write(1, "0x", 2);
		i += ft_putnbr_hex((unsigned long long)p, "0123456789abcdef");
	}
	return (i);
}
