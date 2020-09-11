/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:51:13 by ericard           #+#    #+#             */
/*   Updated: 2020/09/11 12:46:36 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_type(t_flags flags, char c, va_list va)
{
    int ret;

    ret = 0;
    if(c == 'c' || c == 's' || c == '%')
        ret += ft_strings(flags, c, va);
    else if (c == 'd' || c == 'i')
        ret += ft_decimal(flags, va);
    else if(c == 'p')
        ret += 1;
    else if (c == 'u' || c == 'x' || c == 'X')
        ret += 1;
    return (ret);
}