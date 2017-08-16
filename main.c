/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:04:31 by yli               #+#    #+#             */
/*   Updated: 2017/07/11 20:07:21 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int	main(void)
{
	get_info();
	return (0);
}

int	get_info(void)
{
	char		*buf;
	t_info	info;

	ft_memset(&info, 0, sizeof(info));
	while (get_next_line(0, &buf) > 0)
	{
		if (ft_strequ("##start", buf))
			break;
		if (get_ant(buf, &info) < 0)
		{
			write(1, "no ant ERROR\n", 13);
			exit(0);
		}
		/*if (get_room(buf, &info) < 0)
		{
			write(1, "no room ERROR\n", 14);
			exit(0);
		}
		*/
	}
	if (info.ant == 0)
		write(1, "ERROR\n", 7);
	return (0);
}

int get_ant(char *buf, t_info *info)
{
	int	i;

	i = 0;
	if (ft_strequ("", buf) ||
			(ft_strequ("##start", buf) && info->ant == 0) ||
			(ft_strequ("##end", buf) && info->ant == 0) ||
			(((buf[i] < '0') || (buf[i] > '9')) && buf[i] != '#'))
				return (-1);
	else if (ft_strchr("0123456789", *buf))
	{
		while (buf[i])
		{
			if ((buf[i] < '0') || (buf[i] > '9'))
				return (-1);
			i++;
		}
		if (info->ant == 0)
			info->ant = ft_atoi(buf);
		else
			return (-1);
		ft_printf("nbr of ant %ju\n", info->ant);
	}
	return (0);
}

int get_room(char *buf, t_info *info)
{
	while (get_next_line(0, &buf) > 0)
	{
		info->end = 0;
		printf("buf is %s\n", buf);
	}
	return (0);
}

/*

//if ((ft_strcmp("##start", buf) == 0) && (info->ant == 0)) //no start validation
	//return (-1);
*/

/*
int has_char(char *buf, char c)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == c)
			return (0);
		i++;
	}
	return (1);
}
*/
