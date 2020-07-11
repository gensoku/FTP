/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_server_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:05:56 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:05:57 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_SERVER_STRUCT_H
# define FT_P_SERVER_STRUCT_H

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

typedef struct		s_proto_hd
{
	size_t			size;
	void			*file;
}					t_proto_hd;

typedef struct		s_usr_id
{
	char			*name;
	char			*cr_pass;
	int				rights;
	struct s_usr_id	*next;
}					t_usr_id;

typedef struct		s_usr_env
{
	char			*name;
	char			*saved_pwd;
	char			*min_pwd;
	int				rights;
	int				mode_admin;
	int				nc_activated;
	t_usr_id		local;
	t_usr_id		*users;
}					t_usr_env;

#endif
