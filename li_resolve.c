/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:53:01 by zweng             #+#    #+#             */
/*   Updated: 2018/01/31 18:05:00 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		pf_path_contains(int *row, int n, int size)
{
	int 	i = 0;

	while (*(row + i) != -1 && i < size)
	{
		if (*(row + i) == n)
			return (1);
		i++;
	}
	return (0);
}

void	pf_initpath(int *path, int size)
{
	int i = 0;
	while (i < size)
		*(path + i++) = -1;
}

int		pf_calc_dfs(t_data *data, int row, int *path, int index)
{
	int 	i = 0;
	int		size = data->lm_size;
	int		i_min = size + 1;
	int		tmp = size + 1;
	int		pmin = size + 1;

	if (row == size - 1)
		return (1);
	while (i < size)
	{
		if (data->link_map[row][i] != 0 && !pf_path_contains(path, i, index))
		{
			path[index] = i;
			if (data->link_map[row][i] < size + 1 && data->link_map[row][i] < pmin)
			{
				pmin = data->link_map[row][i];
				i_min = i;
			}
			else
			{
				tmp = pf_calc_dfs(data, i, path, index + 1);
				if (data->link_map[row][i] > tmp)
					data->link_map[row][i] = tmp;
				else
					data->link_map[row][i] = 0;
				if (tmp < pmin)
				{
					pmin = tmp;
					i_min = i;
				}
			}
		}
		i++;
	}
	if (i_min == size + 1)
		return (i_min);
	path[index] = i_min;
	return (pmin + 1);
}

int		li_resolve(t_data *data, t_path ***paths)
{
	int		*path;
	t_path	**p;
	int		size;

	size = data->lm_size;
	if (!(p = malloc(sizeof(t_path *) * (size))) ||
		!(path = malloc(sizeof(int) * (size + 1)))
		return (0);
	ft_bzero(p, sizeof(t_path*) * size);
	pf_initpath(path, size);
	path[0] = 0;
	if (!pf_calc_dfs(data, 0, path, 1))
		return (0);
	pf_initpath(path, size);
	li_search_path(data, 0, path, p);
	*paths = p;
	return (1);
}
