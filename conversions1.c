/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:32:15 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/26 02:47:44 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

char	*c_conversion(t_args *args, int c)
{
	char	*ans;
	size_t	i;

	ans = ft_calloc(ft_max(args->width, 1) + 1, sizeof(char));
	if (!ans)
		return (NULL);
	if (args->minus)
	{
		i = 0;
		while (i < (size_t)args -> width - 1)
			ans[i++] = ' ';
		ans[i] = c;
	}
	else
	{
		ans[0] = c;
		i = 1;
		while (i < (size_t)args -> width)
			ans[i++] = ' ';
	}
	return (ans);
}
