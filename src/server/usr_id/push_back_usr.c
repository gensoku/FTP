/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_usr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:39:51 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/25 09:39:52 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		attach_usr(t_usr_env *e, t_usr_id *usr)
{
	t_usr_id	*lead;

	lead = e->users;
	if (!lead)
		e->users = usr;
	else
	{
		while (lead->next)
			lead = lead->next;
		lead->next = usr;
	}
}

static int		del_tab_ret(char **tab, int val)
{
	tab ? ft_del_tab((void **)tab) : 0;
	return (val);
}

int				push_back_usr(t_usr_env *e, char *line)
{
	t_usr_id	*usr;
	char		**split;
	char		*trimed;
	int			len_tab;

	if (!line)
		return (-1);
	if ((usr = (t_usr_id *)malloc(sizeof(t_usr_id))) == NULL)
		return (-1);
	trimed = crypting(line, -1);
	if (!(split = ft_strsplit(trimed, ':')))
	{
		trimed ? ft_memdel((void **)&trimed) : 0;
		return (-1);
	}
	if ((len_tab = ft_len_tab(split)) != 3)
		return (del_tab_ret(split, -1));
	usr->name = split[0] ? ft_strdup(split[0]) : NULL;
	usr->cr_pass = len_tab > 1 ? ft_strdup(split[1]) : NULL;
	usr->rights = len_tab > 2 ? ft_atoi(split[2]) : 0;
	usr->next = NULL;
	attach_usr(e, usr);
	trimed ? ft_memdel((void **)&trimed) : 0;
	split ? ft_del_tab((void **)split) : 0;
	return (1);
}
