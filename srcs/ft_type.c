/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:51:13 by ericard           #+#    #+#             */
/*   Updated: 2020/09/04 14:12:53 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_type(const char *format, size_t *i, va_list va)
{
    int ret;

    ret = 0;
    if(format[*i] == 'c' || format[*i] == 's' || format[*i] == '%')
    {
        ret += ft_strings(format, *i, va);
        (*i)++;
    }
    else if(format[*i] == 'p')
    {
        (*i)++;
    }
    else if(format[*i] == 'd' || format[*i] == 'i')
    {
        (*i)++;
    }
    else if(format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X')
    {
        (*i)++;
    }
    return (ret);
}