/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_send_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 04:46:21 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/18 04:46:22 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int				command_send_cd(char **cmd, int sock, t_usr_env *e)
{
	char		*full;
	int			ret;
	t_proto_hd	hd;

	if (!(full = ft_implode(cmd, ' ')))
		return (-1);
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	display_send(sock, full, 0, 0);
	if ((ret = confirm_cmd(sock, &hd)) == -1)
		return (0);
	else if (ret == 0)
		return (-1);
	if (read_all(sock, &hd) == -1)
		return (-1);
	if (hd.file)
	{
		e->pwd ? free(e->pwd) : 0;
		e->pwd = ft_strdup(hd.file);
	}
	hd.file ? printf("%s\n", (char *)hd.file) : 0;
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (1);
}
