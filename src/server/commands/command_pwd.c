/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 02:16:56 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 02:16:56 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void	pwd_root_usr(int sock)
{
	char	*pwd;

	pwd = ft_pwd();
	display_send(sock, PWD_SUCCESS, 0, ft_strlen(pwd));
	ft_putstr_fd(pwd, sock);
	pwd ? ft_memdel((void **)&pwd) : 0;
}

static char	*set_str_pwd(t_usr_env *e, char *str, char *pwd)
{
	if ((e->rights == 1 && ft_strncmp(e->saved_pwd, pwd,
		ft_strlen(e->saved_pwd))) || (e->rights != 1 &&
		ft_strncmp(e->min_pwd, pwd, ft_strlen(e->min_pwd))))
		display_err(NULL, ERR_PWD);
	if ((e->rights == 1 && !ft_strcmp(pwd, e->saved_pwd)) ||
		(e->rights != 1 && !ft_strcmp(e->min_pwd, pwd)))
		str = ft_strdup("/");
	else
	{
		str = ft_strdup(&pwd[ft_strlen(e->rights == 1 ? e->saved_pwd
			: e->min_pwd)]);
	}
	return (str);
}

void		command_pwd(int sock, char **line, t_usr_env *e)
{
	char	*pwd;
	char	*str;

	if (!line || line[1])
		display_send(sock, PWD_MANY, 0, 0);
	else
	{
		if (e->rights == ROOT_USR)
		{
			pwd_root_usr(sock);
			return ;
		}
		pwd = ft_pwd();
		str = set_str_pwd(e, NULL, pwd);
		display_send(sock, PWD_SUCCESS, 0, ft_strlen(str));
		ft_putstr_fd(str, sock);
		pwd ? ft_memdel((void **)&pwd) : 0;
		str ? ft_memdel((void **)&str) : 0;
	}
}
