/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:46:42 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/10 06:37:25 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

typedef struct s_args
{
	int					hash;
	int					zero;
	int					minus;
	int					space;
	int					plus;
	unsigned int		width;
	int					precision;
	char				conversion;
}	t_args;

int		ft_printf(const char *s, ...);
t_args	*parse(const char *s, size_t *i);
int		c_conversion(t_args *args, int c);
int		s_conversion(t_args *args, const char *s);
int		p_conversion(t_args *args, void *p);
int		u_conversion(t_args *args, unsigned int n);
int		x_conversion(t_args *args, unsigned int n);
int		ft_putnbr_hex(unsigned long long n, const char *digits);
int		hex_len(unsigned long long p);

#endif