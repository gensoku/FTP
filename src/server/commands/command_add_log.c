/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 04:53:22 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/22 04:53:23 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int	open_log_path(t_usr_env *e)
{
	int		fd;
	char	*path;
	char	*complete;

	path = e->saved_pwd;
	complete = ft_strnew(ft_strlen(path) + ft_strlen(DIR_LOGS) + 1);
	ft_strcat(complete, path);
	ft_strcat(complete, DIR_LOGS);
	fd = open(complete, OPEN_OPTS, get_rights());
	complete ? ft_memdel((void **)&complete) : 0;
	return (fd);
}

void		command_add_log(int sock, char **cmd, t_usr_env *e)
{
	int		fd;
	int		ret;

	if (e->mode_admin == DENIED)
		display_send(sock, NOT_EN_RIGHTS, 0, 0);
	else if (!cmd[1])
		display_send(sock, ADD_NOT_EN, 0, 0);
	else
	{
		if ((fd = open_log_path(e)) == -1)
			display_send(sock, ADD_OPN, 0, 0);
		else
		{
			ret = usr_already_exist(cmd[1], e, fd);
			if (ret == -1)
				display_send(sock, USR_ALREADY_EX, 0, 0);
			else if (ret == 1)
				display_send(sock, USR_BAD_FORMAT, 0, 0);
			if (ret == 1 || ret == -1)
				return ;
			if (close(fd) == -1)
				display_err(NULL, CLOSE_FAIL);
			display_send(sock, ADD_SUCCESS, 0, 0);
		}
	}
}
