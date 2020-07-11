/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rooter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 05:18:59 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/15 05:19:01 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int	command_rooter_3(char **split, int sock, t_usr_env *e, int ret)
{
	if (ft_strcmp(split[0], "admin_mode") == 0)
		ret = command_admin_mode(sock, split, e);
	else if (ft_strcmp(split[0], "logout") == 0)
		ret = command_logout(split);
	else if (ft_strcmp(split[0], "help") == 0)
		ret = command_helper(split);
	else if (ft_strcmp(split[0], "rm") == 0)
		ret = command_send_rm(split, sock, 0);
	else if (ft_strcmp(split[0], "rmdir") == 0)
		ret = command_send_rm(split, sock, 1);
	else
	{
		printf("%sunknow command%s\n", RED, RESET);
		ret = 1;
	}
	return (ret);
}

static int	command_rooter_2(char **split, int sock, t_usr_env *e, int ret)
{
	if (ft_strcmp(split[0], "lls") == 0)
		ret = command_local_ls(split);
	else if (ft_strcmp(split[0], "lrm") == 0)
		ret = command_local_rm(split, 0);
	else if (ft_strcmp(split[0], "lrmdir") == 0)
		ret = command_local_rm(split, 1);
	else if (ft_strcmp(split[0], "lmkdir") == 0)
		ret = command_local_mkdir(split);
	else if (ft_strcmp(split[0], "lpwd") == 0)
		ret = command_local_pwd(split);
	else if (ft_strcmp(split[0], "lcd") == 0)
		ret = command_local_cd(split);
	else
		ret = command_rooter_3(split, sock, e, 0);
	return (ret);
}

int			command_rooter(char *line, int sock, t_usr_env *e, int ret)
{
	char	**split;

	if (!(split = ft_strsplit(line, ' ')) || !split[0])
	{
		printf("Failed to check command\n");
		return (1);
	}
	if (ft_strcmp(split[0], "put") == 0)
		ret = command_send_put(split, sock);
	else if (ft_strcmp(split[0], "get") == 0)
		ret = command_send_get(split, sock);
	else if (ft_strcmp(split[0], "ls") == 0)
		ret = command_send_ls(split, sock);
	else if (ft_strcmp(split[0], "pwd") == 0)
		ret = command_send_pwd(split, sock);
	else if (ft_strcmp(split[0], "cd") == 0)
		ret = command_send_cd(split, sock, e);
	else if (ft_strcmp(split[0], "mkdir") == 0)
		ret = command_send_mkdir(split, sock);
	else if (ft_strcmp(split[0], "quit") == 0)
		ret = command_quit(split, sock);
	else
		ret = command_rooter_2(split, sock, e, 0);
	split ? ft_del_tab((void **)split) : 0;
	return (ret);
}
