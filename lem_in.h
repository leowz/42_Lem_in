/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:24:27 by zweng             #+#    #+#             */
/*   Updated: 2018/01/20 22:26:40 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# define F_RM 		1
# define F_LK 		2
# define F_LASTRM 	4
# define F_RM_START 8
# define F_RM_END 	16
# define F_LK_ALC	32
# define F_RM_STAD	64
# define F_RM_EDAD	128

typedef struct	s_room
{
	int			x;
	int			y;
	char		*name;	
}				t_room;

typedef struct	s_data
{
	int			ant_nbr;
	t_list		*ls_rooms;
	char		**rm_names;
	int			**link_map;
	int			lm_size;
}				t_data;

int				li_get_iscomment(char **line);
int				li_get_input(t_data	*data);
int				li_init_linkmap(t_data *data, int *flag);
int				li_lm_get_pos(t_data *data, char *line, int *x, int *y);
t_room			*li_convert_room(char *line);
t_list			*li_newrm(t_room *room);
int				li_ckroom(char *line, int *flag);
int				li_cklink(char *line);
# include "helper.h"
#endif
