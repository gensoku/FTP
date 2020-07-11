/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:08:38 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 09:08:38 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

void					create_client(char const *addr, char const *port)
{
	int					sock;
	struct protoent		*tcp;
	struct sockaddr_in	attr;
	struct hostent		*host;
	char				*err;

	if (!(tcp = getprotobyname(PROTO_NAME)))
		return (display_err(NULL, WRONG_PROTO));
	if ((sock = socket(PF_INET, SOCK_STREAM, tcp->p_proto)) == -1)
		return (display_err(NULL, SOCKET_FAIL));
	if (!ft_strcmp(addr, "Localhost") || !ft_strcmp(addr, "localhost"))
		err = ft_strdup(DUP_LOCAL);
	else
		err = ft_strdup(addr);
	if (!(host = gethostbyname(err)))
		return (display_err(NULL, HOST_FAIL));
	attr.sin_port = htons(ft_atoi(port));
	attr.sin_family = AF_INET;
	attr.sin_addr.s_addr = inet_addr(host->h_name);
	if ((connect(sock, (const struct sockaddr *)&attr, sizeof(attr))) == -1)
		display_err(err, ERR_CONNECT);
	err ? ft_memdel((void **)&err) : 0;
	signal(SIGINT, SIG_IGN);
	ft_send_recv(sock, addr, port);
	close(sock);
}
