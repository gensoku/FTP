/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:29:56 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;
	size_t	i;

	temp = (char *)src;
	temp2 = (char *)dest;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		while (n--)
		{
			temp2[i] = temp[i];
			i++;
		}
		return (dest);
	}
	else if (src < dest)
	{
		while (n--)
			temp2[n] = temp[n];
	}
	return (dest);
}
