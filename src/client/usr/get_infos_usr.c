/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_usr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:01:53 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 10:01:54 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int		set_usr_unknow(t_usr_env *e)
{
	e->pwd = NULL;
	e->usr.name = NULL;
	return (1);
}

static int		set_usr_known(t_usr_env *e, t_proto_hd *hd)
{
	char		**split;

	split = NULL;
	if (!hd->file || !(split = ft_strsplit(hd->file, ':')))
		return (set_usr_unknow(e));
	if (split[0])
		e->usr.name = ft_strdup(split[0]);
	if (split[1])
		e->pwd = ft_strdup(split[1]);
	split ? ft_del_tab((void **)split) : 0;
	return (1);
}

static int		get_usr_infos(int sock, t_usr_env *e)
{
	int			ret;
	t_proto_hd	hd;

	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	if ((ret = confirm_cmd(sock, &hd)) == -1)
		return (set_usr_unknow(e));
	else if (ret == 0)
		return (set_usr_unknow(e));
	if (read_all(sock, &hd) == -1)
		return (set_usr_unknow(e));
	set_usr_known(e, &hd);
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (0);
}

static int		ret_print_usr(char *buff)
{
	if (!ft_strcmp(buff, RCV_NO_LOGS))
	{
		printf("%s%s%s\n", RED, buff, RESET);
		return (-1);
	}
	else
	{
		printf("%s%s%s\n", RED, buff, RESET);
		return (0);
	}
}

int				get_rights_cl(int sock, t_usr_env *e)
{
	char		buff[SIZE_TAMPON + 1];
	int			ret;
	char		**split;

	ft_bzero(buff, SIZE_TAMPON + 1);
	ret = recv(sock, buff, SIZE_TAMPON, 0);
	if (ret > 0)
	{
		if (!ft_strcmp(buff, RCV_NO_LOGS)
			|| !ft_strncmp(buff, "ERROR", ft_strlen("ERROR")))
			return (ret_print_usr(buff));
		else if (ft_strncmp(buff, "SUCCESS", ft_strlen("SUCCESS")) == 0)
		{
			split = ft_strsplit(buff, ':');
			if (split[1])
				ret = ft_atoi(split[1]);
			else
				ret = 0;
			ft_del_tab((void **)split);
			get_usr_infos(sock, e);
			e->usr.rights = ret;
			return (!ret ? 2 : ret);
		}
	}
	return (0);
}
