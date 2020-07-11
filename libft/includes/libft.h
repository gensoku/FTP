/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:09:48 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/19 07:15:50 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# define MOD_H 			1
# define MOD_HH			2
# define MOD_J 			4
# define MOD_L 			8
# define MOD_LL			16
# define MOD_Z			32

# define ATTR_DIEZ		64
# define ATTR_LESS		128
# define ATTR_PLUS		256
# define ATTR_NULL 		512
# define ATTR_SPAC  	1024
# define BUFF_SIZE 		4096

typedef struct			s_foldm
{
	char				*id;
	void				*data;
}						t_foldm;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_str_list
{
	char				*str;
	int					fd;
	char				*cur;
	struct s_str_list	*next;
}						t_str_list;

void					*ft_memset(void *s1, int c, size_t n);
void					ft_bzero(void *s1, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest,
const void *src, int c, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s1, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					ft_str_tolower(char *str);
void					ft_str_toupper(char *str);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *str);
void					ft_striter(char *str, void (*f)(char *));
void					ft_striteri(char *str, void (*f)(unsigned int, char *));
char					*ft_strmap(const char *str, char (*f)(char));
char					*ft_strmapi(const char *str,
char (*f)(unsigned int, char));
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *str,
unsigned int start, size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *str);
char					**ft_strsplit(const char *str, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(const char *str);
void					ft_putendl(const char *str);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *str, int fd);
void					ft_putendl_fd(const char *str, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_putlst_str_endl(t_list **lst);
void					ft_lstappend(t_list **lst, t_list *next);
t_list					*ft_strsplit_lst(const char *str, const char c);
size_t					ft_lst_count(t_list *lst);
int						get_next_line(int fd, char **line);
int						ft_size_long(long ret);
void					ft_str_rev(char *str);
int						ft_isspace(int c);
void					ft_put_tab(char **tab, char c);
char					*ft_str_sub_append(char *src, char *past,
	int start, int cut);

#endif
