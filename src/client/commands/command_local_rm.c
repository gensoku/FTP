/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_local_rm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 05:37:40 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/26 05:37:41 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int			command_local_rm(char **cmd, int opt)
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
		printf("%s%s%s\n", CYAN, !opt ? CL_LOC_RM_SUC : CL_LOC_RMD_SUC, RESET);
		execve(!opt ? "/bin/rm" : "/bin/rmdir", cmd, NULL);
		exit(0);
	}
	return (1);
}
