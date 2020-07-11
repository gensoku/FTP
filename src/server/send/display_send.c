/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_send.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 06:54:48 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 06:54:49 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

void		display_send(int sock, char *line, int opt, unsigned long size)
{
	int		send_t;
	char	*send_buff;

	send_buff = ft_strnew(HEADER_SIZE);
	ft_strcat(send_buff, line);
	ft_memcpy((void *)send_buff + MSG_LEN,
		(void *)&size, sizeof(unsigned long));
	if ((send_t = send(sock, send_buff, HEADER_SIZE, 0)) > 0)
	{
		if (!opt)
		{
			ft_putstr(GREEN);
			ft_putstr("send : ");
			if ((ft_strncmp(line, "SUCCESS", ft_strlen("SUCCESS"))) == 0)
				ft_putstr(CYAN);
			else
				ft_putstr(RED);
			ft_putstr(line);
			ft_putstr(RESET);
		}
	}
	else if (!opt)
		printf("%sfailed to send : %s%s\n", RED, line, RESET);
	send_buff ? ft_memdel((void **)&send_buff) : 0;
}
