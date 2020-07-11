/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_essential.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 05:11:54 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 05:11:55 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void		send_essential(int sock, t_usr_env *e)
{
	char	*cmd;
	char	*pwd;
	char	*dup;

	pwd = ft_pwd();
	if (e->rights == ADMIN_USR)
		dup = ft_strdup(&pwd[ft_strlen(e->saved_pwd)]);
	else if (e->rights != ROOT_USR)
		dup = ft_strdup("/");
	else
		dup = ft_strdup(pwd);
	cmd = ft_strnew(ft_strlen(e->name) + 2 + ft_strlen(dup));
	ft_strcat(cmd, e->name);
	ft_strcat(cmd, ":");
	ft_strcat(cmd, dup);
	display_send(sock, USR_INFO, 1, ft_strlen(cmd));
	send(sock, cmd, ft_strlen(cmd), 0);
	pwd ? ft_memdel((void **)&pwd) : 0;
	dup ? ft_memdel((void **)&dup) : 0;
	cmd ? ft_memdel((void **)&cmd) : 0;
}
