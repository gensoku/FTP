/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_logout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 08:04:44 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/15 08:04:45 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int		command_logout(char **cmd)
{
	if (cmd && cmd[1])
	{
		printf("too many args for <logout> \n");
		return (1);
	}
	return (-2);
}
