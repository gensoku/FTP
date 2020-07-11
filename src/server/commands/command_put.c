/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:08:30 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 09:08:31 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int		confirm_cmd_rights(int sock, t_proto_hd *hd, mode_t *rights)
{
	char		buff[HEADER_SIZE + 1 + sizeof(mode_t)];
	int			ret;

	ft_bzero(buff, HEADER_SIZE + 1 + sizeof(mode_t));
	if ((ret = recv(sock, buff, HEADER_SIZE + sizeof(mode_t), 0)) == 0)
		return (0);
	else
	{
		if (ft_strncmp(buff, "SUCCESS", ft_strlen("SUCCESS")))
			return (-1);
	}
	if (ft_strncmp(buff, "SUCCESS", ft_strlen("SUCCESS")))
		return (-1);
	*rights = *(mode_t *)((void *)buff + MSG_LEN);
	hd->size = *(unsigned long *)((void *)buff + MSG_LEN + sizeof(mode_t));
	return (ret);
}

static int		check_open_get(char *path, mode_t rights)
{
	int			i;
	int			ret;
	char		*real_p;

	i = 0;
	real_p = ft_strnew(ft_strlen(path) + 6);
	ft_strcat(real_p, "./");
	ft_strcat(real_p, path);
	if ((ret = open(path, O_CREAT | O_EXCL | O_RDWR, rights)) == -1)
	{
		while (i <= 9)
		{
			if (i == 0)
				ft_strcat(path, "(0)");
			else
				path[ft_strlen(path) - 2] = i + 48;
			if ((ret = open(path, O_CREAT | O_EXCL | O_RDWR, rights)) != -1)
				break ;
			i++;
		}
	}
	return (ret);
}

static void		send_valid_put(int sock, char *path)
{
	t_proto_hd	hd;
	mode_t		rights;
	int			fd;

	display_send(sock, PUT_GOOD, 1, 0);
	rights = 0;
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	if ((confirm_cmd_rights(sock, &hd, &rights)) == -1)
		display_send(sock, PUT_ERR_RECV, 0, 0);
	else
	{
		if (read_all(sock, &hd) == -1)
		{
			display_send(sock, PUT_ERR_RECV, 0, 0);
			return ;
		}
		if ((fd = check_open_get(path, rights)) == -1)
		{
			display_send(sock, PUT_CREAT_ERR, 0, 0);
			return ;
		}
		hd.file ? write(fd, (char *)hd.file, hd.size) : 0;
		fd != -1 ? close(fd) : 0;
		display_send(sock, PUT_SUCCESS, 0, 0);
	}
}

void			command_put(int sock, char **line, t_usr_env *e)
{
	char		*path;

	if (e->rights == ROOT_USR)
	{
		path = get_local_path(line[1]);
		e->nc_activated ? send_nc_put(sock, path) : send_valid_put(sock, path);
	}
	else if (!(path = get_local_path(line[1])))
		display_send(sock, PUT_PERM, 0, 0);
	else
	{
		if (e->nc_activated)
			send_nc_put(sock, path);
		else
			send_valid_put(sock, path);
	}
	path ? ft_memdel((void **)&path) : 0;
}
