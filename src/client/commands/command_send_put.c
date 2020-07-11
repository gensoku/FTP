/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_send_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:08:17 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 09:08:18 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int		confirm_put(int sock, t_proto_hd *hd)
{
	char		buff[HEADER_SIZE + 1];
	int			ret;

	ft_bzero(buff, HEADER_SIZE + 1);
	if ((ret = recv(sock, buff, HEADER_SIZE, 0)) == 0)
		return (0);
	else
	{
		hd->file = ft_strdup(buff);
		if (!ft_strncmp(buff, "SUCCESS", ft_strlen("SUCCESS")))
			return (1);
		else
			return (-1);
	}
	return (-1);
}

static int		send_full_cmd(char **cmd, int sock)
{
	char		*full;
	t_proto_hd	hd;

	if (!(full = ft_implode(cmd, ' ')))
		display_err(NULL, IMPL_ERR);
	display_send(sock, full, 0, 0);
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	if ((confirm_put(sock, &hd)) == -1)
	{
		hd.file ? printf("%s", hd.file) : 0;
		hd.file ? ft_memdel((void **)&hd.file) : 0;
		return (-1);
	}
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (1);
}

static int		close_mun_both(int fd, char *p, off_t size, int opts)
{
	if (!opts)
	{
		if ((close(fd)) == -1)
			display_err(NULL, CLOSE_ERR);
		if ((munmap((void *)p, size)) == -1)
			display_err(NULL, MUN_ERR);
	}
	else if (opts == 1)
	{
		if ((close(fd)) == -1)
			display_err(NULL, CLOSE_ERR);
	}
	else
	{
		if ((munmap((void *)p, size)) == -1)
			display_err(NULL, MUN_ERR);
	}
	return (1);
}

static int		send_file_cl(int sock, char *p, struct stat *stats)
{
	int			send_t;
	char		*send_buff;
	t_proto_hd	hd;

	send_buff = ft_strnew(HEADER_SIZE + sizeof(mode_t));
	ft_strcat(send_buff, CL_PUT_SUCC);
	ft_memcpy((void *)send_buff + MSG_LEN,
		(void *)&stats->st_mode, sizeof(mode_t));
	ft_memcpy((void *)send_buff + MSG_LEN +
		sizeof(mode_t), (void *)&stats->st_size, sizeof(unsigned long));
	send_t = send(sock, send_buff, HEADER_SIZE + sizeof(mode_t), 0);
	if (send_t != -1)
	{
		write(sock, p, stats->st_size);
		ft_bzero((void *)&hd, sizeof(t_proto_hd));
		if ((send_t = confirm_cmd(sock, &hd)) == -1)
			return (0);
		else if (send_t == 0)
			return (-1);
	}
	send_buff ? ft_memdel((void **)&send_buff) : 0;
	return (1);
}

int				command_send_put(char **cmd, int sock)
{
	int			len;
	int			fd;
	struct stat	stats;
	char		*p;

	if ((len = ft_len_tab(cmd)) != 2)
		return (pf_ret_red(len));
	if ((fd = open(cmd[1], O_RDONLY)) == -1)
		return (pf_ret_red(-1));
	if ((fstat(fd, &stats)) == -1)
	{
		printf("%s%s%s\n", RED, CL_PUT_STAT, RESET);
		return (close_mun_both(fd, NULL, 0, 1));
	}
	if ((p = (char *)mmap(NULL, stats.st_size,
		PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		printf("%s%s%s\n", RED, CL_PUT_MMAP, RESET);
		return (close_mun_both(fd, NULL, 0, 1));
	}
	if ((send_full_cmd(cmd, sock)) == -1)
		return (close_mun_both(fd, p, stats.st_size, 0));
	return (send_file_cl(sock, p, &stats));
}
