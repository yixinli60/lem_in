/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:17:57 by yli               #+#    #+#             */
/*   Updated: 2017/07/11 16:20:22 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "include/libft.h"
# include "include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include <stdio.h>


typedef struct s_info
{
  uintmax_t ant;
  int     st;
  int     end;
}         t_info;

typedef struct s_map
{
  char **map;
}     t_map;

int	get_info(void);
int get_ant(char *buf, t_info *info);
int get_room(char *buf, t_info *info);

//int has_char(char *buf, char c);

#endif
