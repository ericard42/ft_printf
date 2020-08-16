/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:54:55 by ericard           #+#    #+#             */
/*   Updated: 2020/08/16 19:38:29 by ericard          ###   ########.fr       */
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
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			flags = ft_flags(&i, format, va);
			ret += ft_type(format, &i, flags, va);
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			ret++;
		}
		i++;
	}
	va_end(va);
	return (ret);
}
