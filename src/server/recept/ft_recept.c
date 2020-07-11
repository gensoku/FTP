/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:07:57 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 04:07:58 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static void				set_e(t_usr_env *e)
{
	char				*pwd;

	pwd = ft_pwd();
	e->name = ft_strdup(UKN_USR);
	e->rights = STD_USR;
	e->min_pwd = ft_strdup(pwd);
	e->saved_pwd = ft_strdup(pwd);
	e->mode_admin = 0;
	e->nc_activated = 1;
	pwd ? ft_memdel((void **)&pwd) : 0;
}

static int				nc_check_set(int nc, t_usr_env *e, int sock_cs,
	struct sockaddr_in *csaddr)
{
	int					cslen;
	char				*addr;

	cslen = 0;
	if (nc > 0)
	{
		while (cslen == 0)
		{
			cslen = get_id_pwd(sock_cs, e);
			if (cslen < 0)
			{
				addr = inet_ntoa(csaddr->sin_addr);
				printf("%s%s with : %s%s\n", RED, CONEC_FAIL, addr, RESET);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
		set_e(e);
	close(cslen);
	return (1);
}

static void				check_for_nc(int nc, int sock_cs,
	struct sockaddr_in *csaddr)
{
	t_usr_env			e;

	ft_bzero((void *)&e, sizeof(t_usr_env));
	if (nc_check_set(nc, &e, sock_cs, csaddr) != -1)
	{
		display_new_connec(e.name, e.rights);
		nc > 0 ? create_mov_usr_dir(&e, sock_cs) : 0;
		wait_msg(sock_cs, &e, 0, 0);
		destroy_env(&e);
	}
}

void					ft_recept(int sock, int status, int nc)
{
	int					sock_cs;
	unsigned int		cslen;
	struct sockaddr_in	csaddr;
	pid_t				son;

	while ((sock_cs = accept(sock, (struct sockaddr *)&csaddr, &cslen)) > 0)
	{
		son = fork();
		if (son == -1)
			display_err(NULL, FORK_FAIL);
		if (son != 0)
			wait4(son, &status, WNOHANG, 0);
		else
		{
			check_for_nc(nc, sock_cs, &csaddr);
			close(sock_cs);
			exit(0);
		}
		close(sock_cs);
	}
}
