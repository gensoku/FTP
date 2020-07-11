/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 08:45:49 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/15 08:45:50 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int			confirm_cmd(int sock, t_proto_hd *hd)
{
	char	buff[HEADER_SIZE + 1];
	int		ret;

	ft_bzero(buff, HEADER_SIZE + 1);
	if ((ret = recv(sock, buff, HEADER_SIZE, 0)) == 0)
		return (0);
	else if (ret == -1)
		display_err(NULL, RECV_ERR);
	else
	{
		if (!ft_strncmp(buff, "SUCCESS", ft_strlen("SUCCESS")))
			ft_putstr(YELLOW);
		else
			ft_putstr(RED);
		write(1, buff, MSG_LEN);
		ft_putstr(RESET);
	}
	if (ft_strncmp(buff, "SUCCESS", ft_strlen("SUCCESS")) != 0)
		return (-1);
	hd->size = *(unsigned long *)((void *)buff + MSG_LEN);
	return (ret);
}
