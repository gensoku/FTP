/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_send_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 08:30:20 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/15 08:30:21 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int				command_send_pwd(char **cmd, int sock)
{
	int			ret;
	t_proto_hd	hd;

	if (cmd[1])
	{
		printf("%s%s%s\n", RED, CL_PWD_MANY, RESET);
		return (1);
	}
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	display_send(sock, cmd[0], 0, 0);
	if ((ret = confirm_cmd(sock, &hd)) == -1)
		return (0);
	else if (ret == 0)
		return (-1);
	if (read_all(sock, &hd) == -1)
		return (-1);
	hd.file ? printf("%s\n", (char *)hd.file) : printf("\n");
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (1);
}
