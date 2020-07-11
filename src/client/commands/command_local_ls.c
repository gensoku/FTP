/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_local_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:16:35 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/24 02:16:36 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int			command_local_ls(char **cmd)
{
	pid_t	son;
	int		status;

	son = fork();
	if (son == -1)
		display_err(NULL, FORK_FAIL);
	if (son != 0)
		wait4(son, &status, 0, 0);
	else
	{
		printf("%s%s%s\n", CYAN, CL_LOC_LS_SUC, RESET);
		execve("/bin/ls", cmd, NULL);
		exit(0);
	}
	return (1);
}
