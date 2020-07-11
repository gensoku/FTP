/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:49:06 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 09:49:07 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

void		print_prompt(int opt, t_usr_env *e)
{
	if (opt == 0)
	{
		ft_putstr(GREEN);
		ft_putstr("[");
		ft_putstr(e && e->usr.name ? e->usr.name : CL_PROMPT);
		ft_putstr("] ");
		ft_putstr(RED);
		ft_putstr(e->pwd);
		ft_putstr(" ");
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(CYAN);
		if (opt == 1)
			ft_putstr(CL_LOG_PR);
		else
			ft_putendl(CL_PW_PR);
		ft_putstr(RESET);
	}
}
