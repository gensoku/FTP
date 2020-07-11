/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:34:59 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 03:35:00 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"

mode_t			get_rights(void)
{
	mode_t		ret;

	ret = 0;
	ret |= S_IRWXU;
	ret |= S_IRGRP;
	ret |= S_IXGRP;
	ret |= S_IROTH;
	ret |= S_IXOTH;
	return (ret);
}
