/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:31:50 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_add_split(const char *str, const char c, t_list **lst)
{
	size_t i;
	size_t cpt;
	t_list *new;

	i = 0;
	cpt = 0;
	new = NULL;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				cpt++;
				i++;
			}
			if ((new = ft_lstnew(ft_strsub(str, (i - cpt), cpt), (cpt + 1))))
				ft_lstappend(lst, new);
			cpt = 0;
		}
		else
			i++;
	}
}

t_list		*ft_strsplit_lst(const char *str, const char c)
{
	t_list	**lst;
	t_list	*new;

	new = NULL;
	lst = &new;
	if (!str)
		return (NULL);
	ft_add_split(str, c, lst);
	return (*lst);
}
