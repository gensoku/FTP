/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hidden_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:48:37 by tsedigi           #+#    #+#             */
/*   Updated: 2018/10/01 09:48:38 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

int			check_hidden_f(t_usr_env *e, char *line)
{
	char	*chr;

	if (e->rights == ROOT_USR)
		return (0);
	else
	{
		chr = ft_strrchr(line, '/');
		if (chr && ft_strlen(chr) > 1 && chr[1] == '.')
			return (1);
		else if (!chr && ft_strlen(line) > 1 && line[0] == '.')
			return (1);
	}
	return (0);
}
