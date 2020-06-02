/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:59:26 by ericard           #+#    #+#             */
/*   Updated: 2020/05/21 16:55:22 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags     init_flags()
{
    t_flags     flags;
    flags.dot = 0;
    flags.minus = 0;
    flags.star = 0;
    flags.type = 0;
    flags.width = 0;
    flags.zero = 0;
    return(flags);
}

int ft_flags()
{
	int i;

	return (i);
}