/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:03:42 by ericard           #+#    #+#             */
/*   Updated: 2020/10/21 16:16:29 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	calculate_char(int mod, char c)
{
	char	ret;

	if (mod > 36)
		return (0);
	ret = '0';
	while (mod)
	{
		ret++;
		if (ret == ':')
			ret = c;
		mod--;
	}
	return (ret);
}

int		nbrlen(int base, unsigned long int nbr)
{
	int		len;

	len = 0;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int base, unsigned long int nbr, char c)
{
	int		len;
	char	*str;
	int		mod;

	len = nbrlen(base, nbr);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str = ft_memset(str, '\0', len + 1);
	if (nbr == 0)
		*str = '0';
	while (nbr)
	{
		mod = nbr % base;
		nbr /= base;
		str[len - 1] = calculate_char(mod, c);
		len--;
	}
	return (str);
}
