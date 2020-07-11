/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cur_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:38:42 by tsedigi           #+#    #+#             */
/*   Updated: 2018/10/01 09:38:43 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

int					check_cur_point(t_usr_env *e, char *line)
{
	char			*pwd;
	int				ret;

	ret = 0;
	if (!ft_strcmp(line, ".."))
	{
		if (e->rights == ROOT_USR)
			return (0);
		pwd = ft_pwd();
		if (e->rights == ADMIN_USR && !ft_strcmp(pwd, e->saved_pwd))
			ret = 1;
		else if (e->rights == STD_USR && !ft_strcmp(pwd, e->min_pwd))
			ret = 1;
		pwd ? ft_memdel((void **)&pwd) : 0;
	}
	return (ret);
}
