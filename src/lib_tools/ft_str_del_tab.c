/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 05:36:56 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 05:36:57 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"
#include <stdlib.h>

void		ft_del_tab(void **data)
{
	int		i;

	i = 0;
	if (!data)
		return ;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	ft_memdel(data);
}
