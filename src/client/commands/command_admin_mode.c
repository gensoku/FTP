/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_admin_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 05:51:54 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/22 05:51:55 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int				command_admin_mode(int sock, char **cmd, t_usr_env *e)
{
	int			ret;
	t_proto_hd	hd;

	if (cmd[1])
		printf("%s\n", CL_ADMIN_MANY);
	else
	{
		ft_bzero((void *)&hd, sizeof(t_proto_hd));
		display_send(sock, cmd[0], 0, 0);
		if ((ret = confirm_cmd(sock, &hd)) == -1)
			return (0);
		else if (ret == 0)
			return (-1);
		while ((ret = logs_add(sock, 0, e, NULL)) != 2)
		{
			if ((ret = confirm_cmd(sock, &hd)) == 0)
				return (-1);
		}
		display_send(sock, "quit_mode", 0, 0);
		if ((ret = confirm_cmd(sock, &hd)) == -1)
			return (0);
		else if (ret == 0)
			return (-1);
	}
	return (1);
}
