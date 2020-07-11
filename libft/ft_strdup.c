/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:31:03 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if ((copy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str[i] != '\0')
		{
			copy[i] = str[i];
			i++;
		}
		copy[i] = '\0';
	}
	else
		copy = NULL;
	return (copy);
}
