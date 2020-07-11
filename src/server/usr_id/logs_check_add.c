/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_check_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 02:47:24 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/26 02:47:25 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int			alnum_check(char *cmd, int i)
{
	if (!cmd)
		return (1);
	while (cmd[i])
	{
		if (cmd[i] != '\0' && !ft_isalpha(cmd[i])
			&& !ft_isdigit(cmd[i]) && cmd[i] != ':')
			return (1);
		else if (cmd[i] == ':' && (i == 0 || (cmd[i + 1] && cmd[i + 1] == ':')))
			return (1);
		i++;
	}
	return (0);
}

static int			user_exist(t_usr_id *usrs, char *name)
{
	while (usrs)
	{
		if (!ft_strcmp(usrs->name, name))
			return (1);
		usrs = usrs->next;
	}
	return (0);
}

static void			replace_put_usr(char **split,
	t_usr_env *e, char *put, int fd)
{
	char			*tmp;

	split[2] ? free(split[2]) : 0;
	split[2] = crypting("1", 1);
	tmp = ft_implode(split, ':');
	put = crypting(tmp, 1);
	ft_putendl_fd(put, fd);
	push_back_usr(e, put);
	tmp ? ft_memdel((void **)&tmp) : 0;
	put ? ft_memdel((void **)&tmp) : 0;
}

static int			usr_check_errs(char ***to_bind,
	char *cmd, t_usr_env *e, char *decry)
{
	char			**split;
	int				ret;

	ret = 0;
	if (!(split = ft_strsplit(decry, ':')))
		ret = 1;
	if (!split[0] || !split[1] || !split[2])
		ret = 1;
	if (ft_len_tab(split) > 3)
		ret = 1;
	if (alnum_check(cmd, 0))
		ret = 1;
	if (user_exist(e->users, split[0]))
		ret = -1;
	*to_bind = split;
	return (ret);
}

int					usr_already_exist(char *cmd, t_usr_env *e, int fd)
{
	char			**split;
	char			*ri;
	int				right;
	char			*decry;

	decry = crypting(cmd, -1);
	if ((right = usr_check_errs(&split, cmd, e, decry)))
	{
		split ? ft_del_tab((void **)split) : 0;
		decry ? ft_memdel((void **)&decry) : 0;
		return (right);
	}
	decry ? ft_memdel((void **)&decry) : 0;
	ri = crypting(split[2], -1);
	right = ft_atoi(ri);
	ri ? ft_memdel((void **)&ri) : 0;
	if (right == 3 && e->rights != ROOT_USR)
		replace_put_usr(split, e, NULL, fd);
	else
	{
		ft_putendl_fd(cmd, fd);
		push_back_usr(e, cmd);
	}
	split ? ft_del_tab((void **)split) : 0;
	return (0);
}
