/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:03:47 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:03:48 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		print_usage(char *name)
{
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(" < port >", 2);
	ft_putendl_fd(" + av[2](optional for nc)", 2);
	ft_putendl_fd(" + create_logs (optional for adding users)", 2);
	exit(-1);
}

int				main(int ac, char **av)
{
	if (ac == 1 || ac > 4)
		print_usage(av[0]);
	if (ac == 2)
		create_server(av[1], 1);
	else if (ac == 3)
		create_server(av[1], 0);
	else if (ac == 4)
	{
		if (!ft_strcmp(av[3], "create_logs"))
			create_logs(0, 0, NULL);
		else
			print_usage(av[0]);
		exit(0);
	}
	return (EXIT_SUCCESS);
}
