/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rooter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:26:39 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 03:26:40 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		command_rooter_2(int sock,
	t_usr_env *e, char **tab1)
{
	if (ft_strcmp(tab1[0], "mkdir") == 0)
		command_mkdir(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "admin_mode") == 0)
		command_mode_admin(sock, e);
	else if (ft_strcmp(tab1[0], "add_log") == 0)
		command_add_log(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "quit_mode") == 0)
		command_quit_admin(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "rm") == 0)
		command_rm(sock, tab1, e, 0);
	else if (ft_strcmp(tab1[0], "rmdir") == 0)
		command_rm(sock, tab1, e, 1);
	else
		display_send(sock, ERR_CMD, 0, 0);
}

int				command_rooter(char *buff, int sock, t_usr_env *e)
{
	char		**tab1;

	tab1 = NULL;
	if (!buff || !(tab1 = ft_strsplit(buff, ' ')))
		display_send(sock, SND_NO_CMD, 0, 0);
	else if (ft_strcmp(tab1[0], "cd") == 0)
		command_cd(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "ls") == 0)
		command_ls(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "get") == 0)
		command_get(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "put") == 0)
		command_put(sock, tab1, e);
	else if (ft_strcmp(tab1[0], "quit") == 0)
	{
		tab1 ? ft_del_tab((void **)tab1) : 0;
		return (command_quit(sock));
	}
	else if (ft_strcmp(tab1[0], "pwd") == 0)
		command_pwd(sock, tab1, e);
	else
		command_rooter_2(sock, e, tab1);
	tab1 ? ft_del_tab((void **)tab1) : 0;
	return (0);
}
