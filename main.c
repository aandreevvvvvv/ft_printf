/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:46:45 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/10 06:37:53 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	process_plain_text(const char *s, size_t *i)
{
	size_t	len;

	len = 0;
	while (s[*i + len] && s[*i + len] != '%')
		++len;
	write(1, s + *i, len);
	*i += len;
	return (len);
}

int	process_conversion(const char *s, size_t *i, va_list *ap)
{
	t_args	*args;
	int		res;

	res = 0;
	++(*i);
	args = parse(s, i);
	if (!args)
		return (-1);
	if (args->conversion == 'c')
		res = c_conversion(args, va_arg(*ap, int));
	else if (args->conversion == 's')
		res = s_conversion(args, va_arg(*ap, const char *));
	else if (args->conversion == 'p')
		res = p_conversion(args, va_arg(*ap, void *));
	else if (args->conversion == 'u')
		res = u_conversion(args, va_arg(*ap, unsigned int));
	else if (args->conversion == 'x' || args->conversion == 'X')
		res = x_conversion(args, va_arg(*ap, unsigned int));
	else if (args->conversion == '%')
		res = write(1, "%", 1);
	free(args);
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		ans;
	int		res;
	size_t	i;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	ans = 0;
	while (s[i])
	{
		if (s[i] == '%')
			res = process_conversion(s, &i, &ap);
		else
			res = process_plain_text(s, &i);
		if (res == -1)
			return (ans);
		ans += res;
	}
	va_end(ap);
	return (ans);
}
