/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:46:42 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/26 02:38:13 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

typedef struct s_args
{
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	conversion;
}	t_args;

int		ft_printf(const char *s, ...);
t_args	*parse(const char *s, size_t *i);
char	*c_conversion(t_args *args, int c);

#endif