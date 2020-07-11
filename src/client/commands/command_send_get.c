/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_send_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 03:53:38 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/20 03:53:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

static int		confirm_cmd_rights(int sock, t_proto_hd *hd, mode_t *rights)
{
	char		buff[HEADER_SIZE + 1 + sizeof(mode_t)];
	int			ret;

	ft_bzero(buff, HEADER_SIZE + 1 + sizeof(mode_t));
	if ((ret = recv(sock, buff, HEADER_SIZE + sizeof(mode_t), 0)) == 0)
		return (0);
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
	*rights = *(mode_t *)((void *)buff + MSG_LEN);
	hd->size = *(unsigned long *)((void *)buff + MSG_LEN + sizeof(mode_t));
	return (ret);
}

static int		create_file_path(char *path, int i, int ret, mode_t rights)
{
	if ((ret = open(path, O_CREAT | O_EXCL | O_RDWR, rights)) == -1)
	{
		while (i <= 9)
		{
			if (i == 0)
				ft_strcat(path, "(0)");
			else
				path[ft_strlen(path) - 2] = i + 48;
			if ((ret = open(path, O_CREAT | O_EXCL | O_RDWR, rights)) != -1)
				break ;
			i++;
		}
	}
	return (ret);
}

static void		create_new_file(t_proto_hd *hd, mode_t rights, char *name)
{
	char		*path;
	int			ret;
	char		*local;

	if (!hd || !hd->file)
	{
		printf("%s\n", GET_ERR_NEW);
		return ;
	}
	local = get_local_path(name);
	path = ft_strnew(ft_strlen(local) + 4);
	ft_strcat(path, local);
	ret = create_file_path(path, 0, 0, rights);
	local ? ft_memdel((void **)&local) : 0;
	path ? ft_memdel((void **)&path) : 0;
	if (ret != -1)
	{
		if (write(ret, hd->file, hd->size) == -1)
			printf("%s\n", WRITE_ERR);
		if ((close(ret)) == -1)
			display_err(NULL, CLOSE_ERR);
	}
	else
		printf("Error cannot create file on client\n");
}

int				command_send_get(char **cmd, int sock)
{
	char		*full;
	t_proto_hd	hd;
	int			ret;
	mode_t		rights;
	int			len;

	if ((len = ft_len_tab(cmd)) != 2)
	{
		len > 2 ? printf("%s\n", CL_GET_MANY) : printf("%s\n", CL_GET_EN);
		return (1);
	}
	full = ft_implode(cmd, ' ');
	if (!full)
		display_err(NULL, IMPL_ERR);
	display_send(sock, full, 0, 0);
	ft_bzero((void *)&hd, sizeof(t_proto_hd));
	ret = confirm_cmd_rights(sock, &hd, &rights);
	if (ret == 0 || ret == -1)
		return (0);
	if (read_all(sock, &hd) == -1)
		return (-1);
	create_new_file(&hd, rights, cmd[1]);
	hd.file ? ft_memdel((void **)&hd.file) : 0;
	return (1);
}
