/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:53:01 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:20:33 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

void		pf_get_min(t_data *data, int row, int *i, int *i_min)
{
	if ((*i_min == data->lm_size + 1 && data->link_map[row][*i])
			|| (data->link_map[row][*i] != 0 &&
			(data->link_map[row][*i] < data->link_map[row][*i_min])))
	{
		*i_min = *i;
	}
}

void		pf_recursive(t_data *data, int row, int i, int *arr)
{
	arr[i] = 1;
	data->link_map[row][i] = pf_dfs(data, i, arr);
	arr[i] = 0;
}

int			pf_dfs(t_data *data, int row, int *arr)
{
	int		i;
	int		i_min;

	i = 1;
	i_min = data->lm_size + 1;
	if (data->link_map[row][data->lm_size - 1])
		return (2);
	while (i < data->lm_size)
	{
		if (data->link_map[row][i] != 0 && arr[i] != 1)
		{
			if (data->link_map[row][i] < data->lm_size + 1)
				pf_get_min(data, row, &i, &i_min);
			else
			{
				pf_recursive(data, row, i, arr);
				pf_get_min(data, row, &i, &i_min);
			}
		}
		i++;
	}
	if (i_min == data->lm_size + 1 || !data->link_map[row][i_min])
		return (0);
	return (data->link_map[row][i_min] + 1);
}

static int	pf_nbr_path(t_path **ppath)
{
	int		i;

	i = 0;
	while (ppath[i])
		i++;
	return (i);
}

int			li_resolve(t_data *data, t_path ***paths)
{
	int		*path;
	t_path	**p;
	int		size;

	size = data->lm_size;
	if (!(p = malloc(sizeof(t_path *) * (size))) ||
		!(path = malloc(sizeof(int) * (size + 1))))
		return (0);
	ft_bzero(p, sizeof(t_path*) * size);
	pf_initpath(path, size);
	path[0] = 1;
	pf_dfs(data, 0, path);
	pf_initpath(path, size);
	li_search_path(data, 0, path, p);
	ft_memdel((void **)&path);
	li_path_sort(p);
	*paths = p;
	return (pf_nbr_path(p));
}
