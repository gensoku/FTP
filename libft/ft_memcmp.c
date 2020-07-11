/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:29:37 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp1;

	i = 0;
	temp = (unsigned char *)s1;
	temp1 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n)
	{
		if (temp[i] != temp1[i])
			return (temp[i] - temp1[i]);
		i++;
	}
	return (0);
}
