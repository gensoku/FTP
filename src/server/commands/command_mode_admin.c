/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_mode_admin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 04:53:13 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/22 04:53:15 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void			command_mode_admin(int sock, t_usr_env *e)
{
	if (e->rights == ADMIN_USR || e->rights == ROOT_USR)
	{
		display_send(sock, ADMIN_MODE, 0, 0);
		e->mode_admin = ENABLED;
	}
	else
		display_send(sock, DENIED_ADMIN, 0, 0);
}
