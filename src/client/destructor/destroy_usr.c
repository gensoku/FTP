/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_usr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 04:59:17 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 04:59:18 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

void			destroy_usr(t_usr_id *usr)
{
	if (!usr)
		return ;
	usr->name ? ft_memdel((void **)&usr->name) : 0;
	usr->cr_pass ? ft_memdel((void **)&usr->cr_pass) : 0;
}
