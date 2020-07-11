/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 07:19:17 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 07:19:18 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"

int				ft_len_tab(char **array)
{
	int			ret;

	ret = 0;
	if (!array)
		return (ret);
	while (array[ret])
		ret++;
	return (ret);
}
