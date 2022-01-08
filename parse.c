/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:48:57 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/08 23:42:34 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	parse_flags(const char *s, size_t *i, t_args *args)
{
	const char	*flags;

	flags = "#0- +";
	while (s[*i] && ft_strchr(flags, s[*i]))
	{
		if (s[*i] == '#')
			args -> hash = 1;
		else if (s[*i] == '0')
			args -> zero = 1;
		else if (s[*i] == '-')
			args -> minus = 1;
		else if (s[*i] == ' ')
			args -> space = 1;
		else
			args -> plus = 1;
		++(*i);
	}
}

static void	parse_width(const char *s, size_t *i, t_args *args)
{
	args -> width = ft_atoi(s + *i);
	while (ft_isdigit(s[*i]))
		++(*i);
}

static void	parse_precision(const char *s, size_t *i, t_args *args)
{
	if (s[*i] != '.')
	{
		args->precision = 0;
		return ;
	}
	++(*i);
	args->precision = ft_atoi(s + *i);
	while (ft_isdigit(s[*i]))
		++(*i);
}

static int	parse_conversion(const char *s, size_t *i, t_args *args)
{
	const char	*conversions;

	conversions = "cspdiuxX%";
	if (!ft_strchr(conversions, s[*i]))
		return (0);
	args->conversion = s[*i];
	++(*i);
	return (1);
}

t_args	*parse(const char *s, size_t *i)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->hash = 0;
	args->zero = 0;
	args->minus = 0;
	args->space = 0;
	args->plus = 0;
	parse_flags(s, i, args);
	parse_width(s, i, args);
	parse_precision(s, i, args);
	if (!parse_conversion(s, i, args))
	{
		free(args);
		args = NULL;
	}
	return (args);
}
