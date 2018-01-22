/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_input_util2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:33:52 by zweng             #+#    #+#             */
/*   Updated: 2018/01/22 12:26:23 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	pf_init_rm_names(t_data *data)
{
	char	**buf;
	int		i;
	t_list	*node;

	i = 0;
	ft_putstr("enter init rm names\n");
	if ((buf = (char **)malloc(sizeof(char *) * data->lm_size)))
	{
		node = data->ls_rooms;
		data->rm_names = buf;
		while (i < data->lm_size && node != NULL)
		{
			*(buf + i) = ((t_room *)(node->content))->name;
			node = node->next;
			i++;
		}
	ft_putstr("init rm names succes\n");
		return (1);
	}
	ft_putstr("init rm names fails\n");
	return (0);
}

static void	pf_init_map(int **map, int size)
{
	int		i;
	int		j;

	i = 0;
	ft_putstr("enter init map\n");
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = 0;
			j++;	
		}
		i++;
	}
}

int		li_init_linkmap(t_data *data, int *flag)
{
	int		i;

	ft_putstr("enter init linkmap\n");
	if ((data->lm_size = ft_lstsize(data->ls_rooms)) > 0 &&
			pf_init_rm_names(data))
	{
		if ((data->link_map = (int **)malloc(sizeof(int *) * data->lm_size)))
		{
			i = 0;
			while (i < data->lm_size)
			{
				if (!(data->link_map[i] = (int *)malloc(sizeof(int) *
								data->lm_size)))
					return (0);
				i++;
			}
			pf_init_map(data->link_map, data->lm_size);
			*flag += F_LK_ALC;
			ft_putstr("getmap linkmap initalized\n");
			return (1);
		}
	}
	ft_putstr("getmap linkmap failed\n");
	return (0);
}

int		li_lm_get_pos(t_data *data, char *line, int *x, int *y)
{
	int		i;
	char	*ptr;
	int		ret;

	i = 0;
	ret = 0;
	if ((ptr = ft_strchr(line, '-')) && *(ptr + 1) != 0)
	{
		*ptr++ = 0;
		while (i < data->lm_size)
		{
			if (ft_strcmp(data->rm_names[i], line) == 0 && ++ret)
				*x = i;
			if (ft_strcmp(data->rm_names[i], ptr) == 0 && ++ret)
				*y = i;
			i++;
		}
		if (*x == *y)
			ret = 0;
	}
	return (ret == 2 ? 1 : 0);
}
