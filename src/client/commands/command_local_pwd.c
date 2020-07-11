/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_local_pwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:23:47 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/24 02:23:49 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int			command_local_pwd(char **cmd)
{
	char	*pwd;

	if (cmd[1])
	{
		printf("%s\n", CL_PWD_MANY);
		return (1);
	}
	pwd = ft_pwd();
	if (!pwd)
		printf("%s\n", CL_ERR_PWD);
	else
	{
		printf("%s%s%s\n", CYAN, CL_LOC_PW_SUC, RESET);
		printf("%s\n", pwd);
	}
	pwd ? ft_memdel((void **)&pwd) : 0;
	return (1);
}
