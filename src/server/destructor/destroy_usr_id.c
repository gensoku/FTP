/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_usr_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 06:21:52 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 06:21:53 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void			destroy_usr_id(t_usr_id *usr)
{
	if (!usr)
		return ;
	usr->name ? ft_memdel((void **)&(usr->name)) : 0;
	usr->cr_pass ? ft_memdel((void **)&(usr->cr_pass)) : 0;
	usr->rights = 0;
}
