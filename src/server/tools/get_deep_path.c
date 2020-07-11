/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_deep_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 08:04:30 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/26 08:04:32 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static char			*deep_path_home(char **line,
	t_usr_env *e, int i, char *path)
{
	char			*home;

	home = ft_strjoin(e->rights == ADMIN_USR ? e->saved_pwd :
		e->min_pwd, line[i]);
	if (e->rights == ADMIN_USR)
		path = resolve_path(line[i], e->saved_pwd, 0);
	else
		path = resolve_path(line[i], e->min_pwd, 0);
	free(line[i]);
	line[i] = ft_strdup(home);
	ft_memdel((void **)&home);
	return (path);
}

char				*get_deep_path(char **line, t_usr_env *e, int i)
{
	char			*pwd;
	char			*home;
	char			*path;

	if (e->rights == ROOT_USR)
		return (ft_strdup(line[i]));
	if (line[i][0] == '/')
		path = deep_path_home(line, e, i, NULL);
	else
	{
		pwd = ft_pwd();
		path = resolve_path(line[i], pwd, 0);
		pwd ? ft_memdel((void **)&pwd) : 0;
	}
	home = e->rights == ADMIN_USR ? e->saved_pwd : e->min_pwd;
	if (!path)
		return (NULL);
	if (ft_strncmp(path, home, ft_strlen(home)))
	{
		path ? ft_memdel((void **)&path) : 0;
		return (NULL);
	}
	return (path);
}
