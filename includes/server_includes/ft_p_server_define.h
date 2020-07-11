/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_server_define.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:06:08 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:06:08 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_SERVER_DEFINE_H
# define FT_P_SERVER_DEFINE_H

# include "ft_p_server_func.h"

# define PROTO_NAME		"tcp"

# define WRONG_PROTO	"getprotobyname failed, probably wrong protocol name"
# define SOCKET_FAIL	"Call to socket() failed"
# define BIND_FAIL		"Call to bind() failed"
# define SETSOCK_FAIL	"Call to setsocket() failed"
# define FORK_FAIL		"Call to fork() failed"
# define RECV_FAIL		"Recv error"
# define CLOSED_FAIL	"Call to closedir() failed"
# define MUN_FAIL		"Call to munmap() failed"
# define OPEN_FAIL		"Error could not open logs"
# define WRITE_ERR		"Call to write() failed"
# define FSTAT_FAIL		"Call to fstat() failed"

# define CONEC_FAIL		"User failed to connect"
# define USR_ALREADY_EX	"ERROR : user already exist   \n"
# define USR_BAD_FORMAT	"ERROR : bad format for user  \n"

# define USR_INFO		"SUCCESS : info usr send      \n"

# define SND_WRONG_LOGS	"ERROR wrong log/pass"
# define SND_NO_LOGS	"ERROR server no users found"
# define PATH_FAIL		"ERROR while checking path, cannot access users file"
# define SIZE_PATH_FAIL	"ERROR with logs : empty datas"
# define CRPT_PATH_FAIL	"ERROR with logs : corrupted datas"
# define LOGS_FAIL		"ERROR with login checking"
# define SND_NO_CMD		"ERROR : no command           \n"

# define CD_TOO_MANY	"ERROR : too many args : cd   \n"
# define CD_HOME		"ERROR : can't reach home     \n"
# define CD_INVALID		"ERROR : invalid path for cd  \n"
# define CD_REACH		"ERROR : can't reach directory\n"
# define CD_PERM		"ERROR : Permission (user)    \n"
# define CD_PERM_DEN	"ERROR : Permission denied    \n"
# define CD_SUCCESS		"SUCCESS : directory moved    \n"
# define CD_SUC_HOME	"SUCCESS : moved to home '/'  \n"

# define QUIT_SUC		"SUCCESS : user disconnected  \n"

# define MK_PERM		"ERROR : Permission denied    \n"
# define MK_PERM_USR	"ERROR : user perms denied    \n"
# define MK_NO_ARGS		"ERROR : mkdir  <...>         \n"
# define MK_MANY		"ERROR : mkdir too many args  \n"
# define MK_FAIL		"ERROR : mkdir failed         \n"
# define MK_SUCCESS		"SUCCESS : directory Created  \n"

# define PWD_MANY		"ERROR : too many args : pwd  \n"
# define PWD_SUCCESS	"SUCCESS : path printed       \n"

# define LS_MANY		"ERROR : ls too many args     \n"
# define LS_PATH_FAIL	"ERROR : can't access './' dir\n"
# define LS_PERMS		"ERROR : Permission denied    \n"
# define LS_SUCCESS		"SUCCESS : listing directory  \n"

# define GET_PERM		"ERROR : Permission denied    \n"
# define GET_PERM_USR	"ERROR : user perms denied    \n"
# define GET_PATH_ERR	"ERROR : cannot open file     \n"
# define GET_STAT_ERR	"ERROR : cannot read stats    \n"
# define GET_MAP_ERR	"ERROR : cannot map file      \n"
# define GET_SUCC		"SUCCESS : getting file       \n"

# define PUT_PERM		"ERROR : Permission denied    \n"
# define PUT_PERM_USR	"ERROR : user perms denied    \n"
# define PUT_CREAT_ERR	"ERROR : file can't be create \n"
# define PUT_GOOD		"SUCCESS : file can be create \n"
# define PUT_ERR_RECV	"ERROR : recv failed on file  \n"
# define PUT_SUCCESS	"SUCCESS : file created       \n"
# define PUT_SIZE		"ERROR : recv size failed     \n"
# define PUT_SIZE_OK	"SUCCESS : size of file       \n"

# define RM_SUCCESS		"SUCCESS : command rm         \n"
# define RMD_SUCCESS	"SUCCESS : command rmdir      \n"
# define RM_PERMS		"ERROR : Permission denied    \n"

# define NOT_EN_RIGHTS	"ERROR : admin user only      \n"
# define ADD_NOT_EN		"ERROR : no enough args       \n"
# define QUIT_ADM_MANY	"ERROR : too many args        \n"
# define ADD_OPN		"ERROR : open logs failed     \n"
# define ADD_SUCCESS	"SUCCESS : logs added         \n"

# define ADMIN_MODE		"SUCCESS : admin mode enabled \n"
# define DENIED_ADMIN	"ERROR : Permission denied    \n"
# define QUIT_ADMIN_SUC	"SUCCESS : admin mode disabled\n"

# define ERR_CMD		"ERROR : no available command \n"

# define USR_DIR_CREAT	"Failed to create user directory"
# define USR_DIR_FAIL	"Users directory cannot be accessed"
# define DIR_LOGS_FAIL	"Unable to open or create logs"
# define TCGET_FAIL		"Call to tcgetattr() failed"
# define TERM_RESET		"Call to tcsetattr() failed"
# define CLOSE_FAIL		"Call to close() failed"
# define MALLOC_ERR		"Call to malloc() failed"
# define RECV_ERR		"Error with recv() call"
# define ERR_ENTRIE		"Intern ERROR, create_logs"
# define ERR_CHDIR		"Intern ERROR, chdir"
# define ERR_PWD		"Intern ERROR, pwd"
# define DIR_LOGS		"/.logs"
# define DIR_USRS		"./users"

# define NEW_CONNEC		"New, connection with : "
# define ALL_R			" user with admin rights "
# define LIMITED_R		" user with limited rights "
# define ROOT_R			" user root "
# define UKN_USR		"Unknow"
# define ADMIN_USR		1
# define STD_USR		2
# define ROOT_USR		3
# define ENABLED 		1
# define DENIED 		0

# define OPEN_OPTS		(O_RDWR | O_APPEND | O_CREAT | O_SHLOCK)

# define SIZE_TAMPON	10000
# define SIZE_BUFFER	100
# define MAX_SIZE_STR	16
# define MAX_CONECT		42
# define HEADER_SIZE	38
# define MSG_LEN		30
# define MAX_ATTEMPT	10

#endif
