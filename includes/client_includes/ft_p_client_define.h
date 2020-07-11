/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_client_define.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:06:43 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:06:44 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_CLIENT_DEFINE_H
# define FT_P_CLIENT_DEFINE_H

# include "ft_p_client_func.h"

# define PROTO_NAME		"tcp"

# define WRONG_PROTO	"getprotobyname failed, probably wrong protocol name"
# define SOCKET_FAIL	"Call to socket() failed"
# define HOST_FAIL		"gethostbyname failed, wrong address"
# define ERR_CONNECT	"Unable to connect"
# define TCGET_FAIL		"Call to tcgetattr() failed"
# define TERM_RESET		"Call to tcsetattr() failed"
# define RECV_ERR		"Error with recv() call"
# define MALLOC_ERR		"Call to malloc() failed"
# define IMPL_ERR		"Intern Error safety exit"
# define CLOSE_ERR		"Call to close() failed, exit"
# define MUN_ERR		"Call to munmap() failed, exit"
# define FORK_FAIL		"Call to fork() failed, exit"
# define WRITE_ERR		"Call to write() failed"

# define DUP_LOCAL		"127.0.0.1"

# define RCV_NO_LOGS	"ERROR server no users found"

# define CL_PROMPT		"Client"
# define CL_LOG_PR		"[Client] - Login : "
# define CL_PW_PR		"[Client] - pass (hidden) : "
# define CL_RI_PR		"[Client] - Rights 0-9 : "

# define CL_PUT_SUCC	"SUCCESS : sending file stats \n"

# define QUIT_MANY		"Command (quit) too many args"

# define GET_ERR_NEW	"Error while creating new file (get)"

# define CL_ADMIN_MANY	"Error too many args for admin_mode"

# define CL_STOPED		"Connection stoped , exit"
# define CL_LOGOUT		"Logged out "

# define CL_GET_EN		"Command (get) no enough args"
# define CL_GET_MANY	"Command (get) too many args"

# define CL_PWD_MANY	"Command (pwd) too many args"
# define CL_ERR_PWD		"Error with pwd call"

# define CL_MKDIR_EN	"Mkdir no enough args"

# define CL_CD_EN		"Command lcd no enough args"
# define CL_CD_MANY		"Command lcd too many args"
# define CL_CD_INVALID	"Invalid arg for lcd command"
# define CL_CD_SUCCESS	"SUCCESS : local directory moved"

# define LS_SUCCESS		"SUCCESS : listing directory  \n"

# define CL_LOC_LS_SUC	"SUCCESS : local ls"
# define CL_LOC_MK_SUC	"SUCCESS : local mkdir"
# define CL_LOC_PW_SUC	"SUCCESS : local pwd"
# define CL_LOC_RM_SUC	"SUCCESS : local rm"
# define CL_LOC_RMD_SUC	"SUCCESS : local rmdir"

# define RM_SUCCESS		"SUCCESS : command rm         \n"
# define RMD_SUCCESS	"SUCCESS : command rmdir      \n"

# define CL_PUT_MANY	"Command (put) too many args"
# define CL_PUT_EN		"Command (put) no enough args"
# define CL_PUT_OPN		"cannot open file (client)"
# define CL_PUT_STAT	"Error cannot read stats of file"
# define CL_PUT_MMAP	"Error cannot map file"

# define PRINT_SEND		1

# define SIZE_TAMPON	10000
# define MAX_MSG_SIZE	4096
# define SIZE_BUFFER	100
# define HEADER_SIZE	38
# define MSG_LEN		30
# define MAX_ATTEMPT	10

#endif
