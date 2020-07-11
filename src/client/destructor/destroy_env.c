/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 03:37:24 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 03:37:25 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

void		destroy_env(t_usr_env *e)
{
	if (!e)
		return ;
	e->pwd ? ft_memdel((void **)&e->pwd) : 0;
	destroy_usr(&e->usr);
	ft_bzero((void *)&e->usr, sizeof(t_usr_id));
}
