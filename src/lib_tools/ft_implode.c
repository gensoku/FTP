/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 04:48:19 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 04:48:20 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"
#include <stdlib.h>

static int		implode_norm(char **tab1, int i)
{
	int max;

	max = 0;
	while (tab1[i])
	{
		max += ft_strlen(tab1[i]) + 1;
		i++;
	}
	return (max);
}

static char		*implode_norm_2(char **tab1, char c, int i, char *ret)
{
	int	j;
	int	y;

	j = 0;
	y = 0;
	while (tab1[i])
	{
		while (tab1[i][j])
		{
			ret[y] = tab1[i][j];
			j++;
			y++;
		}
		ret[y] = c;
		i++;
		if (!tab1[i])
			ret[y] = 0;
		j = 0;
		y++;
	}
	return (ret);
}

char			*ft_implode(char **tab1, char c)
{
	char		*ret;
	int			max;

	if (!tab1)
		return (NULL);
	if (!c)
		c = ' ';
	max = implode_norm(tab1, 0);
	if ((ret = (char *)malloc(sizeof(char) * max)) == NULL)
	{
		ft_putendl_fd("Call to malloc() failed", 2);
		exit(1);
	}
	return (implode_norm_2(tab1, c, 0, ret));
}
