/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:54:55 by ericard           #+#    #+#             */
/*   Updated: 2020/06/02 11:28:34 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		i;
	va_list 	va;
	int			ret;

	va_start(va, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ret += 
			
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			ret++;
		}
	}
	va_end(va);
	return (ret);
}
