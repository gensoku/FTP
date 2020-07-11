/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 04:33:56 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 04:33:57 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		send_size_rights(int sock, char *line,
	unsigned long size, mode_t rights)
{
	int			send_t;
	char		*send_buff;

	send_buff = ft_strnew(HEADER_SIZE + sizeof(mode_t));
	ft_strcat(send_buff, line);
	ft_memcpy((void *)send_buff + MSG_LEN, (void *)&rights, sizeof(mode_t));
	ft_memcpy((void *)send_buff + MSG_LEN + sizeof(mode_t),
		(void *)&size, sizeof(unsigned long));
	if ((send_t = send(sock, send_buff, HEADER_SIZE + sizeof(mode_t), 0)) > 0)
	{
		ft_putstr(GREEN);
		ft_putstr("send : ");
		if ((ft_strncmp(line, "SUCCESS", ft_strlen("SUCCESS"))) == 0)
			ft_putstr(CYAN);
		else
			ft_putstr(RED);
		ft_putstr(line);
		ft_putstr(RESET);
	}
	else
		printf("%sfailed to send : %s%s\n", RED, line, RESET);
	send_buff ? ft_memdel((void **)&send_buff) : 0;
}

static void		get_send_file(char *p, struct stat *stats,
	int sock, t_usr_env *e)
{
	if (ft_strcmp(e->name, "guest") && ft_strcmp(e->name, UKN_USR))
		send_size_rights(sock, GET_SUCC, stats->st_size, stats->st_mode);
	if (write(sock, p, stats->st_size) == -1)
		printf("%s\n", WRITE_ERR);
}

static int		close_mun_both(int fd, char *p, off_t size, int opts)
{
	if (!opts)
	{
		if (close(fd) == -1)
			display_err(NULL, CLOSE_FAIL);
		if (munmap((void *)p, size) == -1)
			display_err(NULL, MUN_FAIL);
	}
	else if (opts == 1)
	{
		if (close(fd) == -1)
			display_err(NULL, CLOSE_FAIL);
	}
	else
	{
		if (munmap((void *)p, size) == -1)
			display_err(NULL, MUN_FAIL);
	}
	return (1);
}

static int		check_open_get(char *path, int sock, t_usr_env *e)
{
	int			fd;
	char		*p;
	struct stat	stats;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		display_send(sock, GET_PATH_ERR, 0, 0);
		return (1);
	}
	if ((fstat(fd, &stats)) == -1)
	{
		display_send(sock, GET_STAT_ERR, 0, 0);
		return (close_mun_both(fd, NULL, 0, 1));
	}
	if ((p = (char *)mmap(NULL, stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
	{
		display_send(sock, GET_MAP_ERR, 0, 0);
		return (close_mun_both(fd, NULL, 0, 1));
	}
	get_send_file(p, &stats, sock, e);
	return (close_mun_both(fd, p, stats.st_size, 0));
}

void			command_get(int sock, char **line, t_usr_env *e)
{
	char		*path;

	path = NULL;
	if (e->rights == ROOT_USR)
	{
		check_open_get(line[1], sock, e);
		return ;
	}
	if (!(path = get_deep_path(line, e, 1)) || check_cur_point(e, line[1]))
		display_send(sock, GET_PERM, 0, 0);
	else
	{
		if (check_hidden_f(e, line[1]))
			display_send(sock, GET_PERM, 0, 0);
		else if (e->rights == ADMIN_USR &&
			ft_strncmp(path, e->saved_pwd, ft_strlen(e->saved_pwd)))
			display_send(sock, GET_PERM, 0, 0);
		else if (e->rights != ADMIN_USR &&
			ft_strncmp(path, e->min_pwd, ft_strlen(e->min_pwd)))
			display_send(sock, GET_PERM_USR, 0, 0);
		else
			check_open_get(path, sock, e);
	}
	path ? ft_memdel((void **)&path) : 0;
}
