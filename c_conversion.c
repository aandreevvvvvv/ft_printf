/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:32:15 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/09 00:35:28 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int	c_conversion(t_args *args, int c)
{
	size_t	i;

	i = 0;
	if (args->minus)
	{
		i += write(1, &c, 1);
		while (args -> width && i < (size_t)args -> width)
			i += write(1, " ", 1);
	}
	else
	{
		i = 0;
		while (args -> width && i < (size_t)args -> width - 1)
			i += write(1, " ", 1);
		i += write(1, &c, 1);
	}
	return (i);
}
