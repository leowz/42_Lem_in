/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:39:20 by zweng             #+#    #+#             */
/*   Updated: 2018/02/01 19:15:24 by zweng            ###   ########.fr       */
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
			return (i);
		}
		if (data->link_map[row][i] != 0 && data->link_map[row][i] < val
				&& arr[i] != 1 && i != 0)
		{
			arr[row] = 1;
			val = data->link_map[row][i];
			ret = i;
		}
		i++;
	}
	return (ret == data->lm_size ? -1 : ret);
}

static void pf_path(t_data *data, int index, int pos, t_path ***ppath)
{
	if (index == -1)
	{
		free((*(*ppath))->path);
		free(*(*ppath));
		*(*ppath) = NULL;
	}
	else if (index == data->lm_size - 1)
	{
		(*(*ppath))->path[pos] = data->lm_size - 1;
		(*(*ppath))->length = pos + 1;
		(*ppath)++;
	}
}

static int pf_alloc(t_data *data, int *pos, int i, t_path **ppath)
{
	if (!(*ppath))
	{
		if (!(*ppath = malloc(sizeof(t_path))) ||
			!((*ppath)->path = malloc(sizeof(int) * data->lm_size)))
			return (0);
	}
	(*ppath)->path[*pos] = i;
	(*pos)++;
	if (i == data->lm_size - 1)
	{
		(*ppath)->length = *pos;
		return (1);
	}
	return (2);
}



int		li_search_path(t_data *data, int row, int *arr, t_path **ppath)
{
	int		i;
	int		index;
	int		pos;


	i = 0;
	while (i < data->lm_size)
	{
		if (data->link_map[0][i] != 0 && arr[row] != 1)
		{
			pos = 0;
			if ((index = pf_alloc(data, &pos, i, ppath)) < 2)
				return (index);
			index = i;
			while ((index = li_min_index(data, index, arr)) != (data->lm_size - 1)
					&& index != -1 && (arr[index] = 1))
			{
				(*ppath)->path[pos++] = index;
			}
			pf_path(data, index, pos, &ppath);
		}
		i++;
	}
	return (1);
}
