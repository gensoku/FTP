/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_crypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 06:35:24 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 06:35:25 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void	ccat_crypt(char *complete, t_usr_id *usr, char *trimed)
{
	ft_strcat(complete, usr->name);
	ft_strcat(complete, ":");
	ft_strcat(complete, usr->cr_pass);
	ft_strcat(complete, ":");
	ft_strcat(complete, trimed);
}

int			write_crypt(char *trimed, t_usr_id *usr, int fd, t_usr_env *e)
{
	char	*complete;
	char	*tmp;
	char	*crypted;
	int		i;

	i = ft_atoi(trimed);
	tmp = ft_itoa(i);
	ft_memdel((void **)&trimed);
	trimed = crypting(tmp, 1);
	complete = ft_strnew(ft_strlen(usr->name)
		+ ft_strlen(usr->cr_pass) + ft_strlen(trimed) + 3);
	ccat_crypt(complete, usr, trimed);
	crypted = crypting(complete, 1);
	e->rights = ROOT_USR;
	i = usr_already_exist(crypted, e, fd);
	if (i == -1)
		printf("%s\n", USR_ALREADY_EX);
	else if (i == 1)
		printf("%s\n", USR_BAD_FORMAT);
	else
		push_back_usr(e, crypted);
	trimed ? ft_memdel((void **)&trimed) : 0;
	complete ? ft_memdel((void **)&complete) : 0;
	crypted ? ft_memdel((void **)&crypted) : 0;
	return (0);
}
