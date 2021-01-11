/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:50:21 by ericard           #+#    #+#             */
/*   Updated: 2021/01/11 14:45:06 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		flag_list(int c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*'));
}

t_flags			init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.dot = 0;
	flags.prec = 0;
	flags.width = 0;
	return (flags);
}

static t_flags	ft_is_star(va_list va, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(va, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

static size_t	ft_is_dot(t_flags *flags, int i, const char *format, va_list va)
{
	flags->dot = 1;
	if (format[i + 1] == '*' || ft_isdigit(format[i + 1]))
		i++;
	if (format[i] == '*')
	{
		flags->prec = va_arg(va, int);
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			flags->prec = (flags->prec * 10) + (format[i] - 48);
			if (ft_isdigit(format[i + 1]))
				i++;
			else
				break ;
		}
	}
	return (i);
}

int				ft_flags(t_flags *flags, int i, const char *format, va_list va)
{
	while (ft_isdigit(format[i]) == 1 || flag_list(format[i]))
	{
		if (format[i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (format[i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		if (format[i] == '*')
			*flags = ft_is_star(va, *flags);
		if (ft_isdigit(format[i]) == 1)
			flags->width = (flags->width * 10) + (format[i] - 48);
		if (format[i] == '.')
			i = ft_is_dot(flags, i, format, va);
		i++;
	}
	return (i);
}
