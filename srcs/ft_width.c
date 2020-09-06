/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:25:06 by ericard           #+#    #+#             */
/*   Updated: 2020/09/06 20:43:16 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_space(int min)
{
    int i;

    i = 0;
    while (i < min)
    {
        ft_putchar(' ');
        i++;
    }
}

void    ft_print_zero(int min)
{
    int i;
    while (i < min)
    {
        ft_putchar('0');
        i++;
    }
}