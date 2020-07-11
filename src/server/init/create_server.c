/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:12:52 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:12:53 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_server.h"

static int				check_logs_exist(void)
{
	int				fd;
	char			*path;
	char			*complete;
	struct stat		stats;

	path = ft_pwd();
	complete = ft_strnew(ft_strlen(path) + ft_strlen(DIR_LOGS) + 1);
	ft_strcat(complete, path);
	ft_strcat(complete, DIR_LOGS);
	fd = open(complete, O_RDONLY);
	if (!fd || (fstat(fd, &stats) == -1))
		return (0);
	if (close(fd) == -1)
		display_err(NULL, CLOSE_FAIL);
	return (stats.st_size ? 1 : 0);
}

void					create_server(char *port, int i)
{
	int					sock;
	struct protoent		*tcp;
	struct sockaddr_in	attr;
	int					buff;

	if (!(tcp = getprotobyname(PROTO_NAME)))
		return (display_err(NULL, WRONG_PROTO));
	if ((sock = socket(PF_INET, SOCK_STREAM, tcp->p_proto)) == -1)
		return (display_err(NULL, SOCKET_FAIL));
	attr.sin_family = AF_INET;
	attr.sin_port = (htons(ft_atoi(port)));
	attr.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(sock, (const struct sockaddr *)&attr, sizeof(attr))) == -1)
		display_err(NULL, BIND_FAIL);
	buff = SIZE_TAMPON;
	if (setsockopt(sock, SOL_SOCKET, SO_SNDBUF, &buff, sizeof(buff)) == -1)
		display_err(NULL, SETSOCK_FAIL);
	if (setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &buff, sizeof(buff)) == -1)
		display_err(NULL, SETSOCK_FAIL);
	if (i && !check_logs_exist())
		create_logs(0, 0, NULL);
	listen(sock, MAX_CONECT);
	printf("%sServer set, listening connections%s\n", MAGENT, RESET);
	ft_recept(sock, 0, i);
	close(sock);
}
