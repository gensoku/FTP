/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_move_usr_dir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 02:26:16 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 02:26:16 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		move_usr(t_usr_env *e)
{
	e->saved_pwd = ft_pwd();
	if (chdir(DIR_USRS) == -1)
	{
		if (mkdir(DIR_USRS, get_rights()) == -1)
			display_err(NULL, USR_DIR_FAIL);
		if (chdir(DIR_USRS) == -1)
			display_err(NULL, USR_DIR_FAIL);
	}
}

void			create_mov_usr_dir(t_usr_env *e, int sock)
{
	DIR			*dir;
	char		*pwd;
	char		*log_dir;

	move_usr(e);
	pwd = ft_pwd();
	e->mode_admin = 0;
	log_dir = ft_strnew(ft_strlen(pwd) + 2 + ft_strlen(e->name));
	ft_strcat(log_dir, pwd);
	ft_strcat(log_dir, "/");
	ft_strcat(log_dir, e->name);
	pwd ? ft_memdel((void **)&pwd) : 0;
	if ((dir = opendir(log_dir)) == NULL)
	{
		if (mkdir(log_dir, get_rights()) == -1)
			display_err(log_dir, USR_DIR_CREAT);
	}
	if (chdir(log_dir) == -1)
		display_err(NULL, USR_DIR_FAIL);
	else
		e->min_pwd = ft_pwd();
	dir ? closedir(dir) : 0;
	ft_strcmp(e->name, "guest") && ft_strcmp(e->name, UKN_USR) ?
		send_essential(sock, e) : 0;
	log_dir ? ft_memdel((void **)&log_dir) : 0;
}
