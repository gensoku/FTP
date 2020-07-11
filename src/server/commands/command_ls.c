/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 04:21:24 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/24 04:21:25 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int			check_args_path(char **line, int sock, t_usr_env *e)
{
	int				i;
	char			*path;

	i = 0;
	while (line[i] && line[i][0] == '-' && ft_strncmp(line[i], "--", 2))
		i++;
	while (line[i])
	{
		path = get_deep_path(line, e, i);
		if (!path || check_cur_point(e, line[i]))
		{
			display_send(sock, LS_PERMS, 0, 0);
			return (-1);
		}
		path ? ft_memdel((void **)&path) : 0;
		i++;
	}
	return (1);
}

void				command_ls(int sock, char **line, t_usr_env *e)
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
		display_send(sock, LS_SUCCESS, 0, 0);
		dup2(sock, 1);
		dup2(sock, 2);
		execve("/bin/ls", line, NULL);
		exit(0);
	}
	display_send(sock, LS_SUCCESS, 1, 0);
}
