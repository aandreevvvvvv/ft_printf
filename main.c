/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:46:45 by bgohan            #+#    #+#             */
/*   Updated: 2021/12/02 06:17:28 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*process_plain_text(const char *s, size_t *i)
{
	char	*ans;
	size_t	len;
	size_t	j;

	len = 0;
	while (s[*i + len] && s[*i + len] != '%')
		++len;
	ans = malloc((len + 1) * sizeof(char));
	if (!ans)
		return (ans);
	j = 0;
	while (j < len)
	{
		ans[j] = s[*i + j];
		++j;
	}
	ans[j] = 0;
	*i += len;
	return (ans);
}

char	*process_conversion(const char *s, size_t *i, va_list *ap)
{
	t_args	*args;

	++(*i);
	args = parse(s, i);
	if (!args)
		return (NULL);
	if (args -> conversion == 'c')
		return (c_conversion(args, va_arg(*ap, int)));
	else if (args -> conversion == 's')
		return (s_conversion(args, va_arg(*ap, const char *)));
	return (NULL);
}

char	*append(char *s1, char *s2)
{
	char	*new;
	size_t	len;

	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc((len) * sizeof(char));
	if (!new)
	{
		if (s1)
			free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy(new, s1, len);
	ft_strlcat(new, s2, len);
	return (new);
}

int	ft_printf(const char *s, ...)
{
	char	*ans;
	size_t	i;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	ans = NULL;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ans = append(ans, process_conversion(s, &i, &ap));
			if (!ans)
				return (-1);
		}
		else
		{
			ans = append(ans, process_plain_text(s, &i));
			if (!ans)
				return (-1);
		}
	}
	va_end(ap);
	ft_putstr_fd(ans, 0);
	return (ft_strlen(ans));
}
