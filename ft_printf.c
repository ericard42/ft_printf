/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:54:55 by ericard           #+#    #+#             */
/*   Updated: 2020/09/05 13:36:50 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		i;
	va_list 	va;
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
			ret += ft_type(flags, format, i, va);
			i++;
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			ret++;
		}
		i++;
	}
	va_end(va);
	return(ret);
}
