/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_input_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:51:49 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:14:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*li_convert_room(char *line)
{
	t_room	*ret;
	char	*ptr1;
	char	*ptr2;

	ret = 0;
	if ((ptr1 = ft_strchr(line, ' ')) &&
		(ptr2 = ft_strrchr(line, ' ')) &&
		(li_coord_isdigit(ptr1) && li_coord_isdigit(ptr2)) &&
		(ret = (t_room *)malloc(sizeof(t_room))) &&
		(ret->name = ft_strnew(ptr1 - line)))
	{
		ret->x = ft_atoi(ptr1);
		ret->y = ft_atoi(ptr2);
		ft_strncpy(ret->name, line, ptr1 - line);
	}
	return (ret);
}

t_list		*li_newrm(t_room *room)
{
	t_list	*ret;

	ret = 0;
	if ((ret = (t_list *)malloc(sizeof(t_list))))
	{
		ret->content = room;
		ret->content_size = sizeof(t_room);
		ret->next = 0;
	}
	return (ret);
}

int			li_get_iscomment(char **line)
{
	if (**line && (**line == '#') && (ft_strcmp(*line, "##start") != 0) &&
				(ft_strcmp(*line, "##end") != 0))
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

int			li_ckroom(char *line, int *flag)
{
	char	*ptr1;
	char	*ptr2;

	if (*line == '#' && ft_strstr(line, "##start") && !(*flag & F_RM_START))
	{
		*flag += F_RM_START;
		return (1);
	}
	if (*line == '#' && ft_strstr(line, "##end") && !(*flag & F_RM_END))
	{
		*flag += F_RM_END;
		return (1);
	}
	if ((li_strccount(line, ' ') == 2) &&
		(ptr1 = ft_strchr(line, ' ')) &&
		(ptr2 = ft_strrchr(line, ' ')))
	{
		if ((ptr2 - ptr1 > 0) && (ptr1 - line > 0) && *(ptr2 + 1) != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int			li_cklink(char *line)
{
	char	*ptr;

	if (*line != 'L' && *line != '#' && *line != '-')
	{
		if ((ptr = ft_strchr(line, '-')) && ptr - line > 0 && *(ptr + 1) != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
