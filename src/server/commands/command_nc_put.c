/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_nc_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 07:16:44 by tsedigi           #+#    #+#             */
/*   Updated: 2019/01/02 07:16:46 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

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

static int		confirm_cmd_size(int sock, t_proto_hd *hd)
{
	char		buff[MAX_SIZE_STR + 1];
	int			ret;
	long		atoi;

	ft_bzero(buff, MAX_SIZE_STR);
	if ((ret = recv(sock, buff, MAX_SIZE_STR, 0)) == 0)
		return (0);
	if (ret == -1)
		return (-1);
	atoi = ft_atoi_l(buff);
	if (atoi < 0)
		return (-1);
	hd->size = atoi;
	return (ret);
}

void			send_nc_put(int sock, char *path)
{
	t_proto_hd	hd;
	int			fd;

	display_send(sock, PUT_GOOD, 1, 0);
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	if (confirm_cmd_size(sock, &hd) == -1)
		display_send(sock, PUT_SIZE, 1, 0);
	else
	{
		display_send(sock, PUT_SIZE_OK, 1, 0);
		if (read_all(sock, &hd) == -1)
		{
			display_send(sock, PUT_ERR_RECV, 0, 0);
			return ;
		}
		if ((fd = check_open_get(path, get_rights())) == -1)
		{
			display_send(sock, PUT_CREAT_ERR, 0, 0);
			return ;
		}
		hd.file ? write(fd, (char *)hd.file, hd.size) : 0;
		fd != -1 ? close(fd) : 0;
		display_send(sock, PUT_SUCCESS, 0, 0);
	}
}
