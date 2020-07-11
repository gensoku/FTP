/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_lib_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:07:38 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/13 02:07:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_LIB_FUNC_H
# define FT_P_LIB_FUNC_H

# include "libft.h"
# include <sys/stat.h>

void		ft_del_tab(void **data);
char		*ft_pwd(void);
mode_t		get_rights(void);
char		*crypting(char *name, int z);
char		change_c(char c, int plus, int z);
void		ft_set_term(void);
int			ft_len_tab(char **array);
char		*ft_implode(char **tab1, char c);
char		*get_trimed_path(char *name, int i, char *tmp);
char		*get_local_path(char *name);
char		*resolve_path(char *path, char *base, int i);
long		ft_atoi_l(const char *str);

#endif
