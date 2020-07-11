/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 01:57:53 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 01:57:54 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"
#include <stdlib.h>
#include <unistd.h>

char		*ft_pwd(void)
{
	char	*buf;
	char	*ret;

	buf = (char *)malloc(sizeof(char) * MAXPATHLEN + 1);
	ft_bzero(buf, MAXPATHLEN);
	getcwd(buf, MAXPATHLEN);
	ret = ft_strdup(buf);
	ft_memdel((void **)&buf);
	return (ret);
}
