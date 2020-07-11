/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:31:14 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*new;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	new = NULL;
	if ((new = (char*)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			if (i < ft_strlen(s1))
				new[i] = s1[i];
			else
			{
				new[i] = s2[j];
				j++;
			}
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
