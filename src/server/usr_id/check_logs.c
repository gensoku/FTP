/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:20:45 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 04:20:46 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int		get_path_logs(char *buff, t_usr_env *e)
{
	int			fd;
	char		*line;

	fd = 0;
	if (!buff)
		return (-1);
	if ((getcwd(buff, MAXPATHLEN)) == NULL)
		return (-1);
	ft_strcat(buff, DIR_LOGS);
	line = NULL;
	if ((fd = open(buff, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (push_back_usr(e, line) == -1)
			return (-2);
		line ? free(line) : 0;
	}
	line ? ft_memdel((void **)&line) : 0;
	if (close(fd) == -1)
		return (-1);
	return (open(buff, O_RDONLY));
}

static int		set_env_logs(char **line, int sock, t_usr_env *e, char **split)
{
	char		*crypted;
	char		*trimed;

	trimed = NULL;
	if (!split || !split[0] || !split[1] || !split[2])
	{
		split ? ft_del_tab((void **)split) : 0;
		send(sock, SND_WRONG_LOGS, ft_strlen(SND_WRONG_LOGS), 0);
		return (0);
	}
	if (ft_strcmp(split[0], line[0]) == 0 && ft_strcmp(split[1], line[1]) == 0)
	{
		crypted = crypting(split[2], -1);
		e->rights = ft_atoi(crypted);
		e->nc_activated = 0;
		ft_del_tab((void **)split);
		e->name = crypting(line[0], -1);
		trimed = ft_strjoin("SUCCESS:", crypted);
		send(sock, trimed, ft_strlen(trimed), 0);
		trimed ? ft_memdel((void **)&trimed) : 0;
		crypted ? ft_memdel((void **)&crypted) : 0;
		return (e->rights == 0 ? 2 : e->rights);
	}
	split ? ft_del_tab((void **)split) : 0;
	return (-1);
}

static int		fd_path_ret(t_usr_env *e, int sock, int opt)
{
	char		buff[MAXPATHLEN + 1];
	int			fd;
	struct stat	stats;

	if (opt)
	{
		send(sock, SND_WRONG_LOGS, ft_strlen(SND_WRONG_LOGS), 0);
		return (0);
	}
	if ((fd = get_path_logs(&buff[0], e)) < 0)
	{
		send(sock, SND_NO_LOGS, ft_strlen(SND_NO_LOGS), 0);
		printf("%s%s%s\n", RED, fd == -2 ? CRPT_PATH_FAIL : PATH_FAIL, RESET);
		return (-2);
	}
	if (fstat(fd, &stats) == -1)
		display_err(NULL, FSTAT_FAIL);
	if (!stats.st_size)
	{
		send(sock, SND_NO_LOGS, ft_strlen(SND_NO_LOGS), 0);
		printf("%s%s%s\n", RED, SIZE_PATH_FAIL, RESET);
		return (-2);
	}
	return (fd);
}

int				check_logs(char **line, int sock, t_usr_env *e, int ret)
{
	int			fd;
	char		*gnl;
	char		*trimed;
	char		*decrypt;

	fd = fd_path_ret(e, sock, 0);
	gnl = NULL;
	while (get_next_line(fd, &gnl) > 0)
	{
		if (gnl && ft_strlen(gnl) > 0)
		{
			trimed = ft_strtrim(gnl);
			free(gnl);
			if (trimed)
			{
				decrypt = crypting(trimed, -1);
				ret = set_env_logs(line, sock, e, ft_strsplit(decrypt, ':'));
				ft_memdel((void **)&trimed);
				decrypt ? ft_memdel((void **)&decrypt) : 0;
				if (ret != -1)
					return (fd);
			}
		}
	}
	return (fd < 0 ? fd : fd_path_ret(NULL, sock, 1));
}
