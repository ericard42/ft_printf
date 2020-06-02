/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:51:13 by ericard           #+#    #+#             */
/*   Updated: 2020/06/03 01:19:13 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    type(const char *format, int ret, size_t i, t_flags flags, va_list va)
{
    if(format[i] == 'c' || format[i] == 's' || format[i] == '%')
    {
        ret += ft_strings(flags, format + i, va);
        i++;
    }
    else if(format[i] == 'p')
    {
        i++;
    }
    else if(format[i] == 'd' || format[i] == 'i' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
    {
        i++;
    }
}