/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_client_func.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:06:27 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:06:28 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_CLIENT_FUNC_H
# define FT_P_CLIENT_FUNC_H

# include "ft_p_client_struct.h"

void	create_client(char const *addr, char const *port);
void	display_err(char *arg, char *str);
void	print_prompt(int opt, t_usr_env *e);
void	display_send(int sock, char *line, int opt, unsigned long size);
int		ft_send_recv(int sock, char const *addr, char const *port);
int		client_logs_check(int sock, int i, t_usr_env *e, char *tmp);
int		get_rights_cl(int sock, t_usr_env *e);
int		read_all(int sock, t_proto_hd *hd);
int		confirm_cmd(int sock, t_proto_hd *hd);
int		command_rooter(char *line, int sock, t_usr_env *e, int ret);
int		command_logout(char **cmd);
int		command_helper(char **cmd);
int		command_send_pwd(char **cmd, int sock);
int		command_send_cd(char **cmd, int sock, t_usr_env *e);
int		command_send_mkdir(char **cmd, int sock);
int		command_send_ls(char **cmd, int sock);
int		command_quit(char **cmd, int sock);
int		command_send_get(char **cmd, int sock);
int		command_send_put(char **cmd, int sock);
int		command_admin_mode(int sock, char **cmd, t_usr_env *e);
int		command_send_rm(char **cmd, int sock, int opt);
int		logs_add(int sock, int i, t_usr_env *e, char *tmp);
void	destroy_usr(t_usr_id *usr);
void	destroy_env(t_usr_env *e);
int		command_local_ls(char **cmd);
int		command_local_pwd(char **cmd);
int		command_local_cd(char **cmd);
int		command_local_mkdir(char **cmd);
int		command_local_rm(char **cmd, int opt);

int		pf_ret_red(int len);

#endif
