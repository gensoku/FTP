/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_sub_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/19 09:51:47 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_sub_append(char *src, char *past, int start, int cut)
{
	char	*ret;
	char	tmp;
	int		len;

	len = ft_strlen(src);
	if (!src || !past || start > len || start < 0 || cut > len ||
		cut < 0 || start + cut > len)
		return (NULL);
	if ((ret = ft_strnew(len - cut + ft_strlen(past) + 1)) == NULL)
		return (NULL);
	tmp = src[start];
	src[start] = 0;
	ft_strcat(ret, src);
	src[start] = tmp;
	ft_strcat(ret, past);
	ft_strcat(ret, &src[start + cut]);
	return (ret);
}
