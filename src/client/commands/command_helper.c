/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 08:04:33 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/15 08:04:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static void			print_server(void)
{
	ft_putstr("<ls> command ls (server filesystem)\n");
	ft_putstr("<pwd> print current path (server)\n");
	ft_putstr("<cd> move current directory (server)\n");
	ft_putstr("<mkdir> create directory (server)\n");
	ft_putstr("<rmdir> remove a directory (server)\n");
	ft_putstr("<rm> remove files (server) \n");
	ft_putstr("<get 'file' > get a file from serv to client\n");
	ft_putstr("<put 'file' > send a file from client to serv\n");
	ft_putstr("<quit> end connection and exit\n");
	ft_putstr("<logout> end connection\n");
	ft_putstr("<admin_mode> used to create new log/pass");
	ft_putstr(" restricted to users with atleast ADMIN rights\n");
}

int					command_helper(char **cmd)
{
	if (cmd && cmd[1])
		printf("<help> to get a list of command\n");
	else
	{
		printf("****************************\n");
		printf("%s%s%s\n", RED, "command send to server :", YELLOW);
		print_server();
		printf("%s%s\n%s", RESET, "****************************", RED);
		printf("local commands (client) :%s\n", CYAN);
		ft_putstr("<lls> command ls (client filesystem)\n");
		ft_putstr("<lcd> move current directory (client)\n");
		ft_putstr("<lmkdir> create directory (client)\n");
		ft_putstr("<lrmdir> remove directory (client)\n");
		ft_putstr("<lrm> remove files (client)\n");
		printf("<lpwd> print current path (client)\n%s", RESET);
		printf("****************************\n");
	}
	return (1);
}
