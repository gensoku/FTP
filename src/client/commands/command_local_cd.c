/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_local_cd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:31:44 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/24 02:31:44 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int			command_local_cd(char **cmd)
{
	if (!cmd[1])
		printf("%s\n", CL_CD_EN);
	else if (cmd[2])
		printf("%s\n", CL_CD_MANY);
	else
	{
		if (chdir(cmd[1]) == -1)
			printf("%s\n", CL_CD_INVALID);
		else
			printf("%s%s%s\n", CYAN, CL_CD_SUCCESS, RESET);
	}
	return (1);
}
