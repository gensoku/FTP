/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:37:27 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 03:37:28 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"
#include <stdlib.h>

static int	get_max(int i)
{
	if (i < 6)
	{
		if (i == 0)
			return (MAX_0);
		else if (i == 1)
			return (MAX_1);
		else if (i == 2)
			return (MAX_2);
		else if (i == 3)
			return (MAX_3);
		else if (i == 4)
			return (MAX_4);
		else if (i == 5)
			return (MAX_5);
	}
	return (get_max(i % 5));
}

char		*crypting(char *name, int z)
{
	int		i;
	int		plus;
	char	*ret;

	if (!name || ft_strlen(name) == 0)
		return (NULL);
	i = 0;
	plus = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(name) + 1);
	while (name[i])
	{
		plus = get_max(i) + ft_strlen(name);
		ret[i] = change_c(name[i], plus, z);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
