/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:39:20 by zweng             #+#    #+#             */
/*   Updated: 2018/01/31 17:08:58 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	li_min_index(t_data *data, int row, int *arr)
{
	int		i;
	int		val;
	int		ret;

	i = 0;
	val= data->lm_size;
	ret = data->lm_size;
	while (i < data->lm_size)
	{
		if (i == data->lm_size - 1 && data->link_map[row][i] != 0)
		{
			arr[row] = 1;
			return (data->lm_size - 1);
		}
		if (data->link_map[row][i] != 0 && data->link_map[row][i] < val
				&& arr[i] != 1 && i != 0)
		{
			val = data->link_map[row][i];
			ret = i;
		}
		i++;
	}
	return (ret == data->lm_size ? -1 : ret);
}

int		li_search_path(t_data *data, int row, int *arr, t_path **ppath)
{
	int		i = 0;
	int		index;
	int		j;
	int		pos = 0;
	int		**map = data->link_map;
	int		size = data->lm_size;
	while (i < size)
	{
		if (map[0][i] != 0 && arr[row] != 1)
		{
			j = i;
			pos = 0;
			if (!(*ppath))
			{
				*ppath = malloc(sizeof(t_path));
				(*ppath)->path = malloc(sizeof(int) * size);
			}
			(*ppath)->path[pos++] = i;
			while ((index = li_min_index(data, j, arr)) != (size - 1) &&
					index != -1)
			{
				arr[index] = 1;
				arr[i] = 1;
				(*ppath)->path[pos++] = index;
				j = index;
			}
			if (index == -1)
			{
				free((*ppath)->path);
				free(*ppath);
				*ppath = NULL;
			}
			else if (index == size - 1)
			{
				(*ppath)->path[pos++] = size - 1;
				(*ppath)->length = pos;
				ppath++;
			}
		}
		i++;
	}
	return (1);
}
