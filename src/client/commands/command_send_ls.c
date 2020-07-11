/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_send_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 07:33:25 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/19 07:33:26 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int		confirm_cmd_ls(int sock)
{
	char		buff[1025];
	int			ret;
	char		*save;

	ft_bzero(buff, 1024);
	while ((ret = recv(sock, buff, 1024, 0)))
	{
		if (ret == 0)
			return (0);
		else if (ret == -1)
			return (0);
		else
		{
			if ((save = ft_strstr(buff, LS_SUCCESS)))
			{
				save[0] = '\0';
				ft_putstr(buff);
				return (1);
			}
			else
				write(1, buff, ret);
		}
		ft_bzero(buff, 1024);
	}
	return (-1);
}

int				command_send_ls(char **cmd, int sock)
{
	char		*full;
	t_proto_hd	hd;
	int			ret;

	full = ft_implode(cmd, ' ');
	if (!full)
		display_err(NULL, IMPL_ERR);
	display_send(sock, full, 0, 0);
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	if ((ret = confirm_cmd(sock, &hd)) == -1)
		return (0);
	else if (ret == 0)
		return (-1);
	if ((ret = confirm_cmd_ls(sock)) == -1)
		return (0);
	else if (ret == 0)
		return (-1);
	hd.file ? printf("%s\n", (char *)hd.file) : 0;
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (1);
}
