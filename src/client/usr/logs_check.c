/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:48:19 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 09:48:20 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int			get_line_buffer(t_usr_id *usr, int opts)
{
	char			*line;
	char			*trim;
	int				ret;

	ret = -1;
	line = NULL;
	ret = get_next_line(0, &line);
	if (!line)
		return (0);
	trim = ft_strtrim(line);
	if (!trim || ft_strlen(trim) == 0)
	{
		line ? ft_memdel((void **)&line) : 0;
		return (0);
	}
	if (!ft_strcmp(trim, "quit") || !ft_strcmp(trim, "exit"))
		return (2);
	if (!opts)
		usr->name = crypting(trim, 1);
	else
		usr->cr_pass = crypting(trim, 1);
	trim ? ft_memdel((void **)&trim) : 0;
	line ? ft_memdel((void **)&line) : 0;
	return (1);
}

static char			*set_line_crypt(t_usr_id *usr, char *line)
{
	char			*ret;

	line = ft_strnew(ft_strlen(usr->name) + ft_strlen(usr->cr_pass) + 4);
	ft_strcat(line, usr->name);
	ft_strcat(line, ":");
	ft_strcat(line, usr->cr_pass);
	ft_strcat(line, ":0");
	ret = crypting(line, 1);
	line ? ft_memdel((void **)&line) : 0;
	return (ret);
}

static int			loop_check_l(int i, t_usr_id *l_usr, int opt)
{
	print_prompt(opt + 1, NULL);
	while (!(i = get_line_buffer(l_usr, opt)))
		print_prompt(opt + 1, NULL);
	if (i == 2)
		return (-1);
	return (1);
}

int					client_logs_check(int sock, int i, t_usr_env *e, char *tmp)
{
	t_usr_id		l_usr;
	struct termios	old;

	if (tcgetattr(0, &old) == -1)
		display_err(NULL, TCGET_FAIL);
	ft_bzero((void *)&l_usr, sizeof(t_usr_id));
	if ((i = loop_check_l(0, &l_usr, 0)) == -1)
	{
		destroy_usr(&l_usr);
		return (-1);
	}
	ft_set_term();
	if ((i = loop_check_l(0, &l_usr, 1)) == -1)
	{
		destroy_usr(&l_usr);
		return (-1);
	}
	if (tcsetattr(0, TCSAFLUSH, &old) == -1)
		display_err(NULL, TERM_RESET);
	if (!(tmp = set_line_crypt(&l_usr, NULL)))
		return (0);
	tmp ? send(sock, tmp, ft_strlen(tmp), 0) : ft_putchar('\n');
	ft_memdel((void **)&tmp);
	destroy_usr(&l_usr);
	return (get_rights_cl(sock, e));
}
