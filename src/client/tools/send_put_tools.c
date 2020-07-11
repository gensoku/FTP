/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_put_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 02:26:43 by tsedigi           #+#    #+#             */
/*   Updated: 2018/09/27 02:26:44 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p_client.h"

int				pf_ret_red(int len)
{
	if (len == -1)
		printf("%s%s%s\n", RED, CL_PUT_OPN, RESET);
	else
	{
		if (len > 2)
			printf("%s%s%s\n", RED, CL_PUT_MANY, RESET);
		else
			printf("%s%s%s\n", RED, CL_PUT_EN, RESET);
	}
	return (1);
}
