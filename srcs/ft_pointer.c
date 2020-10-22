/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:06:20 by ericard           #+#    #+#             */
/*   Updated: 2020/10/22 15:27:54 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexa_null_dot(t_flags flags)
{
	if (flags.minus == 1)
		ft_putstr("0x", 2);
	if (flags.width > 2)
		ft_print_space(flags.width - 2);
	if (flags.minus == 0)
		ft_putstr("0x", 2);
	return (flags.width > 2 ? flags.width : 2);
}

int		ft_pointer(t_flags flags, va_list va)
{
	char				*print;
	int					ret;
	unsigned long int	nbr;

	nbr = va_arg(va, unsigned long int);
	if (!nbr && flags.dot == 1)
		return (hexa_null_dot(flags));
	print = ft_itoa_base(16, nbr, 'a');
	ret = ft_strlen(print) + 2;
	if (flags.minus == 1)
	{
		ft_putstr("0x", 2);
		ft_putstr(print, ret - 2);
	}
	if (flags.width > ret)
		ft_print_space(flags.width - ret);
	if (flags.minus == 0)
	{
		ft_putstr("0x", 2);
		ft_putstr(print, ret - 2);
	}
	free(print);
	return (flags.width > ret ? flags.width : ret);
}
