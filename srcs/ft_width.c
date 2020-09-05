/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:25:06 by ericard           #+#    #+#             */
/*   Updated: 2020/09/05 15:49:45 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_width_space(int min)
{
    int i;

    i = 0;
    while (i < min)
    {
        ft_putchar(' ');
        i++;
    }
}

void    ft_width_zero(int min)
{
    int i;
    while (i < min)
    {
        ft_putchar('0');
        i++;
    }
}