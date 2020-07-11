/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:13:54 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:13:55 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void	display_err(char *arg, char *str)
{
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putchar_fd(' ', 2);
	}
	str ? ft_putendl_fd(str, 2) : 0;
	exit(EXIT_FAILURE);
}
