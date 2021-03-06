/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:51:13 by ericard           #+#    #+#             */
/*   Updated: 2021/01/10 01:21:00 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(t_flags flags, char c, va_list va)
{
	int ret;

	ret = 0;
	if (c == 'c' || c == 's' || c == '%')
		ret += ft_strings(flags, c, va);
	else if (c == 'd' || c == 'i')
		ret += ft_decimal(flags, va);
	else if (c == 'p')
		ret += ft_pointer(flags, va);
	else if (c == 'x' || c == 'X')
		ret += ft_hexa(flags, va, c);
	else if (c == 'u')
		ret += ft_unsigned(flags, va);
	else
		return (0);
	return (ret);
}
