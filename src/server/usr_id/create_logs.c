/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_logs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:50:39 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 03:50:40 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int			open_log_path(t_usr_env *e)
{
	int				fd;
	char			*path;
	char			*complete;
	char			*line;

	path = ft_pwd();
	complete = ft_strnew(ft_strlen(path) + ft_strlen(DIR_LOGS) + 1);
	ft_strcat(complete, path);
	ft_strcat(complete, DIR_LOGS);
	if ((fd = open(complete, OPEN_OPTS, get_rights())) == -1)
		display_err(NULL, OPEN_FAIL);
	while (get_next_line(fd, &line) > 0)
	{
		push_back_usr(e, line);
		line ? free(line) : 0;
	}
	line ? ft_memdel((void **)&line) : 0;
	if (close(fd) == -1)
		display_err(NULL, CLOSE_FAIL);
	if ((fd = open(complete, OPEN_OPTS, get_rights())) == -1)
		display_err(NULL, OPEN_FAIL);
	path ? ft_memdel((void **)&path) : 0;
	complete ? ft_memdel((void **)&complete) : 0;
	return (fd);
}

static void			print_prompt(int i, struct termios *old)
{
	static int		attempt = 0;

	if (!attempt)
		printf("%s('Quit' to exit logs mode) %s\n", CYAN, RESET);
	if (i == 0)
	{
		printf("%sLogin : %s\n", MAGENT, RESET);
		attempt++;
	}
	else if (i == 1)
	{
		printf("%sPassword [hidden] : %s\n", MAGENT, RESET);
		ft_set_term();
	}
	else
	{
		printf("%sRights [3 - ROOT, 1 ADMIN, other STD USER] : ", MAGENT);
		printf("%s\n", RESET);
		if (tcsetattr(0, TCSAFLUSH, old) == -1)
			display_err(NULL, TERM_RESET);
	}
}

static int			check_entries(char *line, int i, int fd, t_usr_env *e)
{
	char			*trimed;

	if (!line || !(trimed = ft_strtrim(line)))
		return (i);
	if (!ft_strcmp(trimed, "quit") || !ft_strcmp(trimed, "exit"))
	{
		ft_memdel((void **)&trimed);
		return (-1);
	}
	if (i == 0)
	{
		e->local.name = crypting(trimed, 1);
		ft_memdel((void **)&trimed);
		return (1);
	}
	else if (i == 1)
	{
		e->local.cr_pass = crypting(trimed, 1);
		ft_memdel((void **)&trimed);
		return (2);
	}
	else
		return (write_crypt(trimed, &e->local, fd, e));
	return (i);
}

void				create_logs(int fd, int i, char *line)
{
	struct termios	old;
	t_usr_env		e;

	ft_bzero((void *)&e, sizeof(t_usr_env));
	if ((fd = open_log_path(&e)) == -1)
		display_err(NULL, DIR_LOGS_FAIL);
	if (tcgetattr(0, &old) == -1)
		display_err(NULL, TCGET_FAIL);
	while (1)
	{
		print_prompt(i, &old);
		get_next_line(0, &line);
		if ((i = check_entries(line, i, fd, &e)) == -1)
			break ;
		i == 0 ? destroy_usr_id(&e.local) : 0;
		line ? free(line) : 0;
	}
	line ? ft_memdel((void **)&line) : 0;
	destroy_env(&e);
	if (close(fd) == -1)
		display_err(NULL, CLOSE_FAIL);
	if (tcsetattr(0, TCSAFLUSH, &old) == -1)
		display_err(NULL, TERM_RESET);
}
