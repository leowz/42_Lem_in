/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:03:52 by zweng             #+#    #+#             */
/*   Updated: 2018/01/23 19:20:27 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	pf_append_lastroom(t_data *data, t_room *room, int *flag)
{
	t_list	*node;

//	printf("append lastroom\n");
	if ((node = li_newrm(room)))
	{
		ft_lstappend(&(data->ls_rooms), node);
		if (!li_check_lstrooms(data->ls_rooms))
		{
//			printf("room duplication\n");
			return (0);
		}
		if (!(*flag & F_LK))
			*flag += F_LK;
		return (1);
	}
	return (0);
}

static int	pf_get_links(t_data *data, char **line, int *flag, t_room *lrm)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(*flag & F_LK) && !pf_append_lastroom(data, lrm, flag))
	{
//		printf("get link append last fails\n");
		return (0);
	}
	if (!(*flag & F_LK_ALC) && !li_init_linkmap(data, flag))
	{
//		printf("get link init link fails\n");
		return (0);
	}
	if (!li_lm_get_pos(data, *line, &x, &y))
	{
//		printf("get link get pos fails\n");
		return (0);
	}
	if (data->link_map[x][y] == 0 || data->link_map[y][x] == 0)
	{
		data->link_map[x][y] = data->lm_size + 1;
		data->link_map[y][x] = data->lm_size + 1;
	}
	ft_strdel(line);
	return (1);
}

static int	pf_get_rooms(t_data *data, char **line, int *flag, t_room **lsrm)
{
	t_room	*room;
	t_list	*node;

	if ((ft_strstr(*line, "##start") || ft_strstr(*line, "##end")))
		;
	else if ((*flag & F_RM_START) && !(*flag & F_RM_STAD) &&
			!((*flag & F_RM_END) && !(*flag & F_RM_EDAD)) &&
			(room = li_convert_room(*line)) && (node = li_newrm(room)))
	{
//		printf("get start rooms\n");
		*flag += F_RM_STAD;
		ft_lstadd(&(data->ls_rooms), node);
	}
	else if ((*flag & F_RM_END) && !(*flag & F_RM_EDAD) &&
			!((*flag & F_RM_START) && !(*flag & F_RM_STAD)) &&
			(room = li_convert_room(*line)))
	{
//		printf("get end rooms\n");
		*flag += F_RM_EDAD;
		*lsrm = room;
	}
	else if ((room = li_convert_room(*line)) && (node = li_newrm(room)))
	{
//		printf("get normal rooms\n");
		ft_lstappend(&(data->ls_rooms), node);
	}
	else
	{
//		printf("room error\n");
		return (0);
	}
	ft_strdel(line);
	return (1);
}

static int	pf_get_ants(t_data *data, char **line, int *flag)
{
	if (ft_atoi(*line) > 0 && !ft_strchr(*line, '-'))
	{
		data->ant_nbr = ft_atoi(*line);
		ft_strdel(line);
		*flag += F_RM;
//		printf("get ants success\n");
		return (1);
	}
//		printf("get ants fails\n");
	return (0);
}

int			li_get_input(t_data	*data)
{
	char	*line;
	int		flag;
	t_room	*lastroom;

	flag = 0;
	lastroom = NULL;
	while (get_next_line(STDIN_FILENO, &line))
	{
		li_putline(line);
		if (li_get_iscomment(&line))
			continue ;
		else if ((flag == 0) && pf_get_ants(data, &line, &flag))
			continue ;
		else if ((flag & F_RM) && li_ckroom(line, &flag)
				&& pf_get_rooms(data, &line, &flag, &lastroom))
			continue ;
		else if ((flag & F_RM) && (flag & F_RM_STAD) && (flag & F_RM_EDAD)
			&& li_cklink(line) && pf_get_links(data, &line, &flag, lastroom))
			continue ;
		else
			return (0);
	}
	if ((flag & F_RM) && (flag & F_LK) && (flag & F_LK_ALC))
		return (1);
	return (0);
}
