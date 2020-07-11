/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:43:48 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 03:43:49 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"

static char		prev_c(char c)
{
	char		ret;

	ret = c;
	if (c == 'A')
		return ('Z');
	if (c == 'a')
		return ('9');
	if (c == '0')
		return ('z');
	ret--;
	return (ret);
}

static char		next_c(char c)
{
	char		ret;

	ret = c;
	if (c == 'Z')
		return ('A');
	if (c == 'z')
		return ('0');
	if (c == '9')
		return ('a');
	ret++;
	return (ret);
}

char			change_c(char c, int plus, int z)
{
	char		ret;

	ret = c;
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
	{
		while (plus)
		{
			if (z > 0)
				ret = next_c(ret);
			else
				ret = prev_c(ret);
			plus--;
		}
	}
	return (ret);
}
