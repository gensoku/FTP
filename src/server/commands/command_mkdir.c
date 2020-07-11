/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_mkdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 08:21:10 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 08:21:11 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int	mk_check_err_root(int sock, char **array, t_usr_env *e)
{
	if (!array[1])
	{
		display_send(sock, MK_NO_ARGS, 0, 0);
		return (1);
	}
	if (ft_len_tab(array) > 2)
	{
		display_send(sock, MK_MANY, 0, 0);
		return (1);
	}
	if (e->rights == ROOT_USR)
	{
		if (mkdir(array[1], get_rights()) == -1)
			display_send(sock, MK_FAIL, 0, 0);
		else
			display_send(sock, MK_SUCCESS, 0, 0);
		return (1);
	}
	return (0);
}

void		command_mkdir(int sock, char **array, t_usr_env *e)
{
	char	*path;

	if (mk_check_err_root(sock, array, e))
		return ;
	path = get_trimed_path(array[1], 0, NULL);
	if (!path || check_cur_point(e, array[1]))
		display_send(sock, MK_PERM, 0, 0);
	else
	{
		if (e->rights == ADMIN_USR &&
			ft_strncmp(path, e->saved_pwd, ft_strlen(e->saved_pwd)))
			display_send(sock, MK_PERM, 0, 0);
		else if (e->rights != ADMIN_USR &&
			ft_strncmp(path, e->min_pwd, ft_strlen(e->min_pwd)))
			display_send(sock, MK_PERM_USR, 0, 0);
		else
		{
			if (mkdir(path, get_rights()) == -1)
				display_send(sock, MK_FAIL, 0, 0);
			else
				display_send(sock, MK_SUCCESS, 0, 0);
		}
	}
	path ? ft_memdel((void **)&path) : 0;
}
