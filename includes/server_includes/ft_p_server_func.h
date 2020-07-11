/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_server_func.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:05:45 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:05:46 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_SERVER_FUNC_H
# define FT_P_SERVER_FUNC_H

# include "ft_p_server_struct.h"

void	create_server(char *port, int i);
void	ft_recept(int sock, int status, int nc);
int		get_id_pwd(int sock, t_usr_env *e);
int		check_logs(char **line, int sock, t_usr_env *e, int ret);
int		usr_already_exist(char *cmd, t_usr_env *e, int fd);
int		push_back_usr(t_usr_env *e, char *line);
void	send_essential(int sock, t_usr_env *e);
void	create_mov_usr_dir(t_usr_env *e, int sock);
void	wait_msg(int sock, t_usr_env *e, int ret, int q);
int		read_all(int sock, t_proto_hd *hd);
void	display_err(char *arg, char *str);
void	display_new_connec(char *name, int rights);
void	create_logs(int fd, int i, char *line);
int		write_crypt(char *trimed, t_usr_id *usr, int fd, t_usr_env *e);
void	destroy_usr_id(t_usr_id *usr);
void	destroy_env(t_usr_env *e);
void	display_send(int sock, char *line, int opt, unsigned long size);
int		command_rooter(char *buff, int sock, t_usr_env *e);
void	command_cd(int sock, char **array, t_usr_env *e);
void	command_mkdir(int sock, char **array, t_usr_env *e);
void	command_pwd(int sock, char **line, t_usr_env *e);
void	command_ls(int sock, char **line, t_usr_env *e);
int		command_quit(int sock);
void	command_get(int sock, char **line, t_usr_env *e);
void	command_put(int sock, char **line, t_usr_env *e);
void	send_nc_put(int sock, char *path);
void	command_add_log(int sock, char **cmd, t_usr_env *e);
void	command_quit_admin(int sock, char **cmd, t_usr_env *e);
void	command_mode_admin(int sock, t_usr_env *e);
void	command_rm(int sock, char **line, t_usr_env *e, int opt);
char	*get_deep_path(char **line, t_usr_env *e, int i);
int		check_cur_point(t_usr_env *e, char *line);
int		check_hidden_f(t_usr_env *e, char *line);

#endif
