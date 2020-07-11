/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_local_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:11:46 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/24 02:11:47 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"

char			*get_local_path(char *name)
{
	char		*chr;

	chr = ft_strrchr(name, '/');
	if (chr && ft_strlen(chr) > 1)
		return (ft_strdup(&chr[1]));
	return (ft_strdup(name));
}
