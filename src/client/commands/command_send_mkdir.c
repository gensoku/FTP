/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_send_mkdir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 06:25:59 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/19 06:26:00 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int				command_send_mkdir(char **cmd, int sock)
{
	char		*full;
	t_proto_hd	hd;
	int			ret;

	if (!cmd[1])
	{
		printf("%s\n", CL_MKDIR_EN);
		return (1);
	}
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	if (!(full = ft_implode(cmd, ' ')))
		display_err(NULL, IMPL_ERR);
	display_send(sock, full, 0, 0);
	if ((ret = confirm_cmd(sock, &hd)) == -1)
		return (0);
	else if (ret == 0)
		return (-1);
	if (read_all(sock, &hd) == -1)
		return (-1);
	hd.file ? printf("%s\n", (char *)hd.file) : 0;
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (1);
}
