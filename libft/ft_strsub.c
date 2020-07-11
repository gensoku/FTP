/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:31:55 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	size_t			i;
	char			*new;

	i = 0;
	if ((new = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			new[i] = str[start];
			i++;
			start++;
		}
		new[i] = '\0';
	}
	else
		new = NULL;
	return (new);
}
