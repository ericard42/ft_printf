/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:54:55 by ericard           #+#    #+#             */
/*   Updated: 2021/01/11 14:10:37 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		va;
	int			ret;
	t_flags		flags;

	va_start(va, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		flags = init_flags();
		if (format[i] == '%' && format[i + 1])
		{
			i = ft_flags(&flags, ++i, format, va);
			ret += ft_type(flags, format[i], va);
		}
		else if (format[i] != '%' && format[i])
		{
			ft_putchar(format[i]);
			ret++;
		}
		format[i] != 0 ? i++ : 0;
	}
	va_end(va);
	return (ret);
}
