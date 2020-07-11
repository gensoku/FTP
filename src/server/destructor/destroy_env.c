/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 05:04:47 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/26 05:04:50 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void			destroy_env(t_usr_env *e)
{
	t_usr_id	*id;
	t_usr_id	*tmp;

	if (!e)
		return ;
	e->name ? ft_memdel((void **)&e->name) : 0;
	e->saved_pwd ? ft_memdel((void **)&e->saved_pwd) : 0;
	e->min_pwd ? ft_memdel((void **)&e->min_pwd) : 0;
	id = e->users;
	while (id)
	{
		tmp = id;
		id = id->next;
		destroy_usr_id(tmp);
	}
	e->local.name ? ft_memdel((void **)&e->local.name) : 0;
	e->local.cr_pass ? ft_memdel((void **)&e->local.cr_pass) : 0;
}
