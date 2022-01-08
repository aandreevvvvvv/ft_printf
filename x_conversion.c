/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:40:47 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/09 02:15:23 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_puthex(unsigned long long n, const char *digits)
{
	int		digit;

	digit = n % 16;
	n /= 16;
	if (n)
		ft_puthex(n, digits);
	write(1, digits + digit, 1);
}
