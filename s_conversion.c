/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:27:16 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/09 02:02:31 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

int	s_conversion(t_args *args, const char *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (write(1, "(null)", 6));
	if (args->precision == -1)
		len = ft_strlen(s);
	else
		len = ft_min(ft_strlen(s), args->precision);
	i = 0;
	if (args->minus)
	{
		i += write(1, s, len);
		while (args->width && i < (size_t)args->width)
			i += write(1, " ", 1);
	}
	else
	{
		while (args->width && i < (size_t)args->width + len)
			i += write(1, " ", 1);
		i += write(1, s, len);
	}
	return (i);
}
