/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 07:17:24 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 07:17:25 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		send_plus_update(int sock, char *msg, t_usr_env *e)
{
	char		*pwd;
	char		*dup;

	pwd = ft_pwd();
	dup = NULL;
	if (e->rights == 1 && ft_strcmp(pwd, e->saved_pwd))
		dup = ft_strdup(&pwd[ft_strlen(e->saved_pwd)]);
	else if (e->rights != 1 && ft_strcmp(e->min_pwd, pwd))
		dup = ft_strdup(&pwd[ft_strlen(e->min_pwd)]);
	else
		dup = ft_strdup("/");
	display_send(sock, msg, 0, ft_strlen(dup));
	dup ? ft_putstr_fd(dup, sock) : 0;
	dup ? ft_memdel((void **)&dup) : 0;
	pwd ? ft_memdel((void **)&pwd) : 0;
}

static void		command_cd_check(char *save, char *futur,
	t_usr_env *e, int sock)
{
	if ((e->rights == 1 &&
		ft_strncmp(e->saved_pwd, futur, ft_strlen(e->saved_pwd)) != 0)
		|| (e->rights != 1 &&
		ft_strncmp(e->min_pwd, futur, ft_strlen(e->min_pwd)) != 0))
	{
		if (chdir(save) == -1)
			display_err(NULL, ERR_CHDIR);
		display_send(sock, CD_PERM_DEN, 0, 0);
	}
	else
	{
		if (e->rights == 1)
			send_plus_update(sock, CD_SUCCESS, e);
		else if (!ft_strncmp(e->min_pwd, futur, ft_strlen(e->min_pwd)))
			send_plus_update(sock, CD_SUCCESS, e);
		else
		{
			if (chdir(save) == -1)
				display_err(NULL, ERR_CHDIR);
			display_send(sock, CD_PERM, 0, 0);
		}
	}
}

static void		command_cd_no_arg(t_usr_env *e, int sock)
{
	char		*pwd;

	if ((e->rights == ROOT_USR || e->rights == ADMIN_USR)
		&& chdir(e->saved_pwd) == -1)
		display_send(sock, CD_HOME, 0, 0);
	else if ((e->rights != ROOT_USR && e->rights != ADMIN_USR)
		&& chdir(e->min_pwd) == -1)
		display_send(sock, CD_HOME, 0, 0);
	else
	{
		if (e->rights == ROOT_USR)
		{
			pwd = ft_pwd();
			display_send(sock, CD_SUC_HOME, 0, ft_strlen(pwd));
			ft_putstr_fd(pwd, sock);
			pwd ? ft_memdel((void **)&pwd) : 0;
			return ;
		}
		display_send(sock, CD_SUC_HOME, 0, 1);
		ft_putstr_fd("/", sock);
	}
}

static int		check_root_cd(t_usr_env *e, int sock, char **array)
{
	char		*pwd;

	if (e->rights != ROOT_USR)
		return (0);
	if (chdir(array[1]) == -1)
	{
		display_send(sock, CD_INVALID, 0, 0);
		return (1);
	}
	pwd = ft_pwd();
	display_send(sock, CD_SUCCESS, 0, ft_strlen(pwd));
	ft_putstr_fd(pwd, sock);
	pwd ? ft_memdel((void **)&pwd) : 0;
	return (1);
}

void			command_cd(int sock, char **array, t_usr_env *e)
{
	char		*save;
	char		*futur;

	if (ft_len_tab(array) > 2)
	{
		display_send(sock, CD_TOO_MANY, 0, 0);
		return ;
	}
	if (!array[1] || !ft_strcmp(array[1], "/"))
	{
		command_cd_no_arg(e, sock);
		return ;
	}
	if (check_root_cd(e, sock, array))
		return ;
	save = ft_pwd();
	if (chdir(array[1]) == -1)
	{
		display_send(sock, CD_INVALID, 0, 0);
		return ;
	}
	futur = ft_pwd();
	command_cd_check(save, futur, e, sock);
	save ? ft_memdel((void **)&save) : 0;
	futur ? ft_memdel((void **)&futur) : 0;
}
