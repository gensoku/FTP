/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_send.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 01:56:38 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 01:56:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

void		display_send(int sock, char *line, int opt, unsigned long size)
{
	int		send_t;
	char	*send_buff;

	send_buff = ft_strnew(MAX_MSG_SIZE + 1);
	ft_strcat(send_buff, line);
	if (size)
	{
		ft_memcpy((void *)send_buff + MSG_LEN,
			(void *)&size, sizeof(unsigned long));
	}
	if ((send_t = send(sock, send_buff, MAX_MSG_SIZE, 0)) > 0)
	{
		if (opt & PRINT_SEND)
		{
			printf("%ssend : ", GREEN);
			if ((ft_strncmp(line, "SUCCESS", ft_strlen("SUCCESS"))) == 0)
				ft_putstr(CYAN);
			else
				ft_putstr(RED);
			printf("%s%s\n", line, RESET);
		}
	}
	else
		printf("%sfailed to send : %s%s\n", RED, line, RESET);
	send_buff ? ft_memdel((void **)&send_buff) : 0;
}
