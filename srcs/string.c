/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:55:34 by ericard           #+#    #+#             */
/*   Updated: 2020/06/03 01:26:54 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_strings(t_flags flags, const char *format, va_list va)
{
    int ret;

    if (format == 's')
    {

    }
    if (format == 'c')
    {

    }
    if (format == '%')
    {
        ft_putchar('%');
        ret = 1;
    }
    return (ret);
}