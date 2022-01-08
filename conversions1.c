/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:32:15 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/08 23:56:23 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int	c_conversion(t_args *args, int c)
{
	size_t	i;

	if (args->minus)
	{
		write(1, &c, 1);
		i = 1;
		while (args -> width && i < (size_t)args -> width)
		{
			write(1, " ", 1);
			++i;
		}
	}
	else
	{
		i = 0;
		while (args -> width && i < (size_t)args -> width - 1)
		{
			write(1, " ", 1);
			++i;
		}
		write(1, &c, 1);
		++i;
	}
	return (i);
}

/*
char	*s_conversion(t_args *args, const char *s)
{
	char	*ans;
	size_t	i;
	size_t	len;

	i = 0;
	if (args -> precision)
	{
		ans = malloc((args -> precision + 1) * sizeof(char));
		if (!ans)
			return (ans);
		while (i < (size_t) args -> precision)
		{
			ans[i] = s[i];
			++i;
		}
	}
	else
	{
		len = ft_strlen(s);
		ans = malloc((len + 1) * sizeof(char));
		if (!ans)
			return (ans);
		while (i < len)
		{
			ans[i] = s[i];
			++i;
		}
	}
	return (ans);
}
*/