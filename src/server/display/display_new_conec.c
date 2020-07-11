/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_new_connec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 02:09:38 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 02:09:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void		display_new_connec(char *name, int rights)
{
	printf("%s%s%s%s%s%s : ", GREEN, NEW_CONNEC, RESET, YELLOW, name, RESET);
	if (rights == ADMIN_USR)
		printf("%s\n", ALL_R);
	else if (rights == ROOT_USR)
		printf("%s\n", ROOT_R);
	else
		printf("%s\n", LIMITED_R);
}
