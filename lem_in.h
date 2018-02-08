/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:24:27 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:35:49 by zweng            ###   ########.fr       */
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

typedef	struct	s_ant
{
	int			n_path;
	int			n_room;
}				t_ant;

typedef	struct	s_path
{
	int			*path;
	int			length;
}				t_path;

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
int				li_check_lstrooms(t_list *lst);
int				li_strccount(char *str, char c);
int				li_coord_isdigit(char *str);
void			li_putline(char *str);
int				li_resolve(t_data *data, t_path ***paths);
void			li_print_res(t_data *data, t_path **paths);
int				li_search_path(t_data *data, int row,
				int *arr, t_path **ppath);
int				li_remain_ants(t_ant *ants, int i);
int				li_pt_flag(int flag);
int				li_have_pathone(t_path **paths);
t_ant			*pf_new_ants(t_data *data);
void			pf_increase(int *flag, int i, t_ant *ants);
#endif
