/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:21:36 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 05:21:37 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int			main(int ac, char const **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putendl_fd(" < addr > < port >", 2);
		return (EXIT_FAILURE);
	}
	create_client(av[1], av[2]);
	return (EXIT_SUCCESS);
}
