/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:56:19 by ericard           #+#    #+#             */
/*   Updated: 2020/09/09 22:07:33 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	if (s == NULL)
	{
		if (!(new = malloc(sizeof(char) * (1))))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	i = ft_strlen(s);
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}