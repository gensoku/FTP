/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 02:01:34 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 02:01:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int			ret_sz_dt(unsigned long count, t_proto_hd *hd, char *data)
{
	if (count == hd->size)
	{
		hd->file = (void *)data;
		return (1);
	}
	else
	{
		data ? ft_memdel((void **)&data) : 0;
	}
	return (-1);
}

int					read_all(int sock, t_proto_hd *hd)
{
	int				ret;
	unsigned long	count;
	char			buff[SIZE_BUFFER];
	char			*data;

	count = 0;
	if (!hd->size)
		return (1);
	if (!(data = (char *)malloc(hd->size + 1)))
		display_err(NULL, MALLOC_ERR);
	ft_bzero((void *)data, hd->size + 1);
	while (count < hd->size)
	{
		ft_bzero(buff, SIZE_BUFFER);
		ret = recv(sock, &buff, SIZE_BUFFER, 0);
		if (ret == -1)
			display_err(NULL, RECV_ERR);
		else
		{
			ft_memcpy((void *)data + count, (void *)buff, ret);
			count += ret;
		}
	}
	return (ret_sz_dt(count, hd, data));
}
