/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:28:34 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_check(char *str, int n)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
		return (0);
	}
	return (1);
}

static int	ft_size(int n)
{
	int size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*new;

	size = ft_size(n);
	new = NULL;
	if ((new = (char*)malloc(sizeof(char*) * size + 1)))
	{
		if ((ft_check(new, n) == 0))
			return (new);
		new[size] = '\0';
		size--;
		if (n < 0)
		{
			new[0] = '-';
			n = -n;
		}
		while (n > 9)
		{
			new[size] = ((n % 10) + '0');
			n /= 10;
			size--;
		}
		new[size] = (n + '0');
	}
	return (new);
}
