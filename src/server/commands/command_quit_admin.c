/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_quit_admin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 04:54:05 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/22 04:54:06 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void		command_quit_admin(int sock, char **cmd, t_usr_env *e)
{
	if (cmd[1])
	{
		display_send(sock, QUIT_ADM_MANY, 0, 0);
	}
	else
	{
		display_send(sock, QUIT_ADMIN_SUC, 0, 0);
		e->mode_admin = DENIED;
	}
}
