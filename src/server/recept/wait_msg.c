/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:16:50 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 03:16:51 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void		print_msg(char *line, t_usr_env *e)
{
	printf("%sReceived from  %s : %s%s", YELLOW, e->name, RESET, WHITE);
	printf("%s", line);
	if (line[ft_strlen(line) - 1] != '\n')
		printf("\n");
	printf("%s", RESET);
}

static void		print_quit(t_usr_env *e, int q)
{
	if (q == -1)
		printf("%sConnection lost with %s%s\n", RED, e->name, RESET);
	else
		printf("%sUser : %s logged out%s\n", BLUE, e->name, RESET);
}

void			wait_msg(int sock, t_usr_env *e, int ret, int q)
{
	char		buff[SIZE_TAMPON + 1];
	char		*line;

	while (1)
	{
		ft_bzero(buff, SIZE_TAMPON + 1);
		if ((ret = recv(sock, &buff, SIZE_TAMPON, 0)) > 0)
		{
			if ((line = ft_strtrim(buff)) && ft_strlen(line) > 0)
			{
				print_msg(line, e);
				if ((q = command_rooter(line, sock, e)) < 0)
				{
					print_quit(e, q);
					break ;
				}
			}
			line ? free(line) : 0;
		}
		else if (ret == 0)
		{
			print_quit(e, -1);
			break ;
		}
	}
}
