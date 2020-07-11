/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:31:23 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	size_t	i;
	char	*new;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str[i])
		{
			new[i] = (*f)(str[i]);
			i++;
		}
		new[i] = '\0';
	}
	else
		new = NULL;
	return (new);
}
