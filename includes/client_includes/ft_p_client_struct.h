/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_client_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:06:34 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:06:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_CLIENT_STRUCT_H
# define FT_P_CLIENT_STRUCT_H

# include <netdb.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <termios.h>
# include <dirent.h>
# include <sys/mman.h>
# include "ft_p_lib.h"

typedef struct	s_proto_hd
{
	size_t		size;
	void		*file;
	size_t		nb;
}				t_proto_hd;

typedef struct	s_usr_id
{
	char		*name;
	char		*cr_pass;
	int			rights;
	int			sock;
}				t_usr_id;

typedef struct	s_usr_env
{
	t_usr_id	usr;
	char		*pwd;
}				t_usr_env;

#endif
