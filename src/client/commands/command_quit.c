/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 03:08:37 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 03:08:38 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int				command_quit(char **cmd, int sock)
{
	t_proto_hd	hd;
	int			ret;

	if (ft_len_tab(cmd) > 1)
	{
		printf("%s\n", QUIT_MANY);
		return (1);
	}
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	display_send(sock, cmd[0], 0, 0);
	if ((ret = confirm_cmd(sock, &hd)) == -1)
		return (0);
	else if (ret == 0)
		return (-1);
	return (-1);
}
