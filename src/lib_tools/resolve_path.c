/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 06:24:42 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/24 06:24:43 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"

static int	path_back(char *chr, char *eval)
{
	chr = ft_strrchr(eval, '/');
	if (!chr)
	{
		eval ? ft_memdel((void **)&eval) : 0;
		return (-1);
	}
	ft_bzero((void *)chr, ft_strlen(chr));
	return (1);
}

static int	valid_path(char *chr, char *path, char *eval, int i)
{
	int		up;

	chr = ft_strchr(&path[i], '/');
	up = chr ? chr - &path[i] : ft_strlen(&path[i]);
	chr ? chr[0] = '\0' : 0;
	ft_strcat(eval, "/");
	ft_strcat(eval, &path[i]);
	chr ? chr[0] = '/' : 0;
	return (up ? up : 1);
}

char		*resolve_path(char *path, char *base, int i)
{
	char	*eval;

	if (!path)
		return (NULL);
	eval = ft_strnew(ft_strlen(path) * 2 + ft_strlen(base) + 2);
	ft_strcat(eval, base);
	while (path[i] && path[i] == '/')
		i++;
	while (path[i])
	{
		if (!ft_strncmp(&path[i], "./", 2))
			i += 2;
		else if (!ft_strncmp(&path[i], "../", 3))
		{
			if (path_back(NULL, eval) == -1)
				return (NULL);
			i += 3;
		}
		else if (path[i] != '/')
			i += valid_path(NULL, path, eval, i);
		else
			i++;
	}
	return (eval);
}
