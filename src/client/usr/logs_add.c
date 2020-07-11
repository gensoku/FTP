/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 05:11:54 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/22 05:11:55 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static void			print_prompt_ad(int opt, t_usr_env *e)
{
	ft_putstr(GREEN);
	ft_putstr("[ Add new user, 'quit_mode' to exit ]");
	(void)e;
	ft_putstr(RED);
	if (opt == 1)
		ft_putstr(" Login : ");
	else if (opt == 2)
		ft_putstr(" Password (hidden) : ");
	else
		ft_putstr(" Rights (0-9) : ");
	ft_putstr(RESET);
}

static int			get_line_buffer(t_usr_id *usr, int opts)
{
	char			*line;
	char			*trim;
	int				ret;

	ret = -1;
	line = NULL;
	ret = get_next_line(0, &line);
	trim = ft_strtrim(line);
	if (!trim || ft_strlen(trim) == 0 || (opts == 2 && ft_strlen(trim) != 1))
	{
		line ? ft_memdel((void **)&line) : 0;
		return (0);
	}
	if (!ft_strcmp(trim, "quit_mode"))
		return (2);
	if (!opts)
		usr->name = crypting(trim, 1);
	else if (opts == 1)
		usr->cr_pass = crypting(trim, 1);
	else
		usr->rights = ft_atoi(trim);
	trim ? ft_memdel((void **)&trim) : 0;
	line ? ft_memdel((void **)&line) : 0;
	return (1);
}

static char			*set_line_crypt(t_usr_id *usr, char *line)
{
	char			*ret;
	char			*ito;
	char			*to_send;
	char			*tmp;

	line = ft_strnew(ft_strlen(usr->name) + ft_strlen(usr->cr_pass) + 4);
	ito = ft_itoa(usr->rights);
	ft_strcat(line, usr->name);
	ft_strcat(line, ":");
	ft_strcat(line, usr->cr_pass);
	ft_strcat(line, ":");
	tmp = crypting(ito, 1);
	ft_strcat(line, tmp);
	tmp ? ft_memdel((void **)&tmp) : 0;
	ret = crypting(line, 1);
	to_send = ft_strnew(ft_strlen(ret) + ft_strlen("add_log ") + 1);
	ft_strcat(to_send, "add_log ");
	ft_strcat(to_send, ret);
	line ? ft_memdel((void **)&line) : 0;
	ito ? ft_memdel((void **)&ito) : 0;
	ret ? ft_memdel((void **)&ret) : 0;
	return (to_send);
}

static int			loop_get_l(int i, t_usr_id *l_usr, int opt, t_usr_env *e)
{
	print_prompt_ad(opt + 1, e);
	while (!(i = get_line_buffer(l_usr, opt)))
		print_prompt_ad(opt + 1, e);
	if (i == 2)
		return (i);
	return (1);
}

int					logs_add(int sock, int i, t_usr_env *e, char *tmp)
{
	t_usr_id		l_usr;
	struct termios	old;

	if (tcgetattr(0, &old) == -1)
		display_err(NULL, TCGET_FAIL);
	ft_bzero((void *)&l_usr, sizeof(t_usr_id));
	if ((i = loop_get_l(0, &l_usr, 0, e)) == 2)
	{
		destroy_usr(&l_usr);
		return (i);
	}
	ft_set_term();
	i = loop_get_l(0, &l_usr, 1, e);
	if (tcsetattr(0, TCSAFLUSH, &old) == -1)
		display_err(NULL, TERM_RESET);
	if (i == 2 || ((i = loop_get_l(0, &l_usr, 2, e)) == 2))
	{
		destroy_usr(&l_usr);
		return (i);
	}
	tmp = set_line_crypt(&l_usr, NULL);
	tmp ? send(sock, tmp, ft_strlen(tmp), 0) : ft_putchar('\n');
	ft_memdel((void **)&tmp);
	destroy_usr(&l_usr);
	return (1);
}
