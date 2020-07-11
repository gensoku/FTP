/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:17:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/02/15 04:32:05 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

static int		gnl_check_stock(char **stock, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int		gnl_check_read(char *buffer, char **stock, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

static int		gnl_returns(int ret, char **stock, char **line)
{
	if (ret == -1)
		return (-1);
	if (*stock == NULL)
		return (0);
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	return (0);
}

static char		**gnl_initialize(void)
{
	int		fd_max;
	int		fd_cursor;
	char	**stock_new;

	fd_cursor = 0;
	fd_max = 257;
	stock_new = malloc(sizeof(char**) * fd_max);
	while (fd_max--)
	{
		stock_new[fd_cursor] = ft_strnew(0);
		fd_cursor++;
	}
	stock_new[fd_cursor] = ft_strnew(0);
	return (stock_new);
}

int				get_next_line(int const fd, char **line)
{
	static char		**stock;
	char			*buffer;
	int				ret;

	if (fd < 0 || fd > 256 || !line)
		return (-1);
	if (!stock)
		stock = gnl_initialize();
	if (stock[fd])
		if (gnl_check_stock(&stock[fd], line))
			return (1);
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (gnl_check_read(buffer, &stock[fd], line))
			return (1);
		stock[fd] = ft_strjoin(stock[fd], buffer);
	}
	free(buffer);
	buffer = NULL;
	if (ret == 0 && !stock[fd])
		*line = NULL;
	return (gnl_returns(ret, &stock[fd], line));
}
