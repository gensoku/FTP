/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 06:18:31 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/14 06:18:32 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_lib.h"
#include <termios.h>

void				ft_set_term(void)
{
	struct termios	curent;

	if (tcgetattr(0, &curent) == -1)
		return ;
	curent.c_lflag &= ~(ICANON);
	curent.c_lflag &= ~(ECHO | ISIG);
	curent.c_cc[VMIN] = 1;
	curent.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSAFLUSH, &curent) == -1)
		return ;
}
