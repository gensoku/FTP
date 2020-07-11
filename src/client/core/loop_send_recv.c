/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_send_recv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:45:26 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 09:45:27 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int		check_to_rooter(char *line, t_usr_env *e, int sock)
{
	char		*trim;
	int			ret;

	if (!line || ft_strlen(line) == 0)
		return (0);
	if (!(trim = ft_strtrim(line)) || ft_strlen(trim) == 0)
		return (0);
	ret = command_rooter(trim, sock, e, 0);
	ret == -1 ? printf("%s%s%s\n", RED, CL_STOPED, RESET) : 0;
	ret == -2 ? printf("%s%s%s\n", BLUE, CL_LOGOUT, RESET) : 0;
	trim ? ft_memdel((void **)&trim) : 0;
	return (ret);
}

static int		loop_send_recv(t_usr_env *e, int sock, int ret)
{
	char		*line;

	line = NULL;
	while (1)
	{
		print_prompt(0, e);
		if (get_next_line(0, &line) > 0)
		{
			ret = check_to_rooter(line, e, sock);
			line ? ft_memdel((void **)&line) : 0;
			if (ret == -1 || ret == -2)
			{
				line ? ft_memdel((void **)&line) : 0;
				return (ret);
			}
		}
		line ? ft_memdel((void **)&line) : 0;
	}
	line ? ft_memdel((void **)&line) : 0;
	return (ret);
}

int				ft_send_recv(int sock, char const *addr, char const *port)
{
	int			ret;
	t_usr_env	e;

	ret = 0;
	ft_bzero((void *)&e, sizeof(t_usr_env));
	while (!ret)
		ret = client_logs_check(sock, 0, &e, NULL);
	if (ret == -1)
		return (ret);
	ret = loop_send_recv(&e, sock, 0);
	destroy_env(&e);
	if (ret == -2)
	{
		close(sock);
		create_client(addr, port);
	}
	return (ret);
}
