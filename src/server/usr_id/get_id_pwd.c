/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:17:02 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 04:17:03 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int		set_guest_user(t_usr_env *e, int ret)
{
	if (ret)
		return (-1);
	e->rights = STD_USR;
	e->name = ft_strdup("guest");
	e->saved_pwd = NULL;
	e->min_pwd = NULL;
	return (2);
}

int				get_id_pwd(int sock, t_usr_env *e)
{
	char		buff[SIZE_TAMPON + 1];
	int			ret;
	char		**line;
	char		*decrypt;

	ft_bzero(buff, SIZE_TAMPON + 1);
	if (((ret = recv(sock, &buff, SIZE_TAMPON, 0)) == -1) || ret == 0)
		return (-1);
	if (buff[ft_strlen(buff) - 1] == '\n')
		buff[ft_strlen(buff) - 1] = '\0';
	if (!ft_strcmp(buff, "quit") || !ft_strcmp(buff, "guest"))
		return (set_guest_user(e, !ft_strcmp(buff, "quit") ? 1 : 0));
	decrypt = crypting(buff, -1);
	line = ft_strsplit(decrypt, ':');
	decrypt ? ft_memdel((void **)&decrypt) : 0;
	if (!line || !line[1] || !(ft_strlen(line[1])))
	{
		send(sock, SND_WRONG_LOGS, ft_strlen(SND_WRONG_LOGS), 0);
		return (0);
	}
	ret = check_logs(line, sock, e, 0);
	ft_del_tab((void **)line);
	return (ret);
}
