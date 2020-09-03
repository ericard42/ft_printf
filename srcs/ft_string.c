/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:55:34 by ericard           #+#    #+#             */
/*   Updated: 2020/09/03 14:34:51 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_s(va_list va)
{
    int     ret;
    char    *print;

    ret = 0;
    print = ft_strdup(va_arg(va, char *));
    ret = ft_strlen(print);
    ft_putstr(print);
    return (ret);
}

int     ft_char(va_list va)
{
    int     ret;

    ret = 1;
    ft_putchar(va_arg(va, int));
    return (ret);
}

int     ft_strings(const char *format, size_t i, va_list va)
{
    int     ret;

    ret = 0;
    if (format[i] == 's')
        ret = ft_s(va);
    if (format[i] == 'c')
        ret = ft_char(va);
    if (format[i] == '%')
    {
        ft_putchar('%');
        ret = 1;
    }
    return (ret);
}