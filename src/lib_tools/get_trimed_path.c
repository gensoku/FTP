/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trimed_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 04:48:15 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 04:48:16 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"

char		*get_trimed_path(char *name, int i, char *tmp)
{
	char	*chr;
	char	*ret;

	tmp = ft_pwd();
	ret = NULL;
	while (name[i] && !ft_strncmp(&name[i], "../", 3))
	{
		if (!(chr = ft_strrchr(tmp, '/')) || ft_strlen(chr) == 1)
		{
			tmp ? ft_memdel((void **)&tmp) : 0;
			return (NULL);
		}
		ft_memset((void *)chr, '\0', ft_strlen(chr));
		i += 3;
	}
	if (name[i])
	{
		ret = ft_strnew(ft_strlen(tmp) + ft_strlen(&name[i]) + 2);
		ft_strcat(ret, tmp);
		ft_strcat(ret, "/");
		ft_strcat(ret, &name[i]);
	}
	tmp ? ft_memdel((void **)&tmp) : 0;
	return (ret);
}
