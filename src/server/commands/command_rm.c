/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 05:37:16 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/26 05:37:17 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static char			*deep_path_home(char **line,
	t_usr_env *e, int i, char *path)
{
	char			*home;

	home = ft_strjoin(e->min_pwd, line[i]);
	path = resolve_path(line[i], e->min_pwd, 0);
	free(line[i]);
	line[i] = ft_strdup(home);
	ft_memdel((void **)&home);
	return (path);
}

static char			*get_deep_path_rm(char **line, t_usr_env *e, int i)
{
	char			*pwd;
	char			*home;
	char			*path;

	if (e->rights == ROOT_USR)
		return (ft_strdup(line[i]));
	if (line[i][0] == '/')
		path = deep_path_home(line, e, i, NULL);
	else
	{
		pwd = ft_pwd();
		path = resolve_path(line[i], pwd, 0);
		pwd ? ft_memdel((void **)&pwd) : 0;
	}
	home = e->min_pwd;
	if (!path)
		return (NULL);
	if (ft_strncmp(path, home, ft_strlen(home)) || !ft_strcmp(path, home))
	{
		path ? ft_memdel((void **)&path) : 0;
		return (NULL);
	}
	return (path);
}

static int			check_args_path(char **line, int sock, t_usr_env *e)
{
	int				i;
	char			*path;

	i = 0;
	while (line[i] && line[i][0] == '-' && ft_strncmp(line[i], "--", 2))
		i++;
	while (line[i])
	{
		path = get_deep_path_rm(line, e, i);
		if (!path || check_cur_point(e, line[i]))
		{
			display_send(sock, RM_PERMS, 0, 0);
			return (-1);
		}
		path ? ft_memdel((void **)&path) : 0;
		i++;
	}
	return (1);
}

void				command_rm(int sock, char **line, t_usr_env *e, int opt)
{
	pid_t			son;
	int				status;

	if (line[1] && (check_args_path(&line[1], sock, e)) == -1)
		return ;
	son = fork();
	if (son == -1)
		display_err(NULL, FORK_FAIL);
	if (son != 0)
		wait4(son, &status, 0, 0);
	else
	{
		display_send(sock, !opt ? RM_SUCCESS : RMD_SUCCESS, 0, 0);
		dup2(sock, 1);
		dup2(sock, 2);
		execve(!opt ? "/bin/rm" : "/bin/rmdir", line, NULL);
		exit(0);
	}
	display_send(sock, !opt ? RM_SUCCESS : RMD_SUCCESS, 1, 0);
}
