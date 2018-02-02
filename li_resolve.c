/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:53:01 by zweng             #+#    #+#             */
/*   Updated: 2018/02/01 22:30:16 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

/*static void	pf_get_min(int *ele, int tmp)
{
	if (*ele >= tmp)
		*ele = tmp;
	else
		*ele = 0;
}*/

void pf_print_path(int *path, int size)
{
	int		i;

	i = 0;
	printf("path| ");
	while (i < size)
	{
		printf("%d-> ", path[i]);
		i++;
	}
	printf("|\n");
}

int		pf_calc_dfs(t_data *data, int row, int *path, int index)
{
	t_var	v;

	pf_init_va(&v, data->lm_size);
	if (row == data->lm_size - 1)
		return (1);
	while (v.i < data->lm_size)
	{
		if (row == 21 && v.i == 57)
		{
				printf("row %d, i %d is %d\n",row, v.i, data->link_map[row][v.i]);
				printf("can enter calcu %d\n",!pf_contains(path, v.i, index));
				pf_print_path(path, index);	
		}
		if (data->link_map[row][v.i] != 0 && !pf_contains(path, v.i, index))
		{
			if (row == 57 && v.i == 26)
				printf("57 26 tmp %d\n", v.tmp);
			path[index] = v.i;
			if (data->link_map[row][v.i] < data->lm_size + 1 && data->
			link_map[row][v.i] < v.pmin && (v.pmin = data->link_map[row][v.i]))
			{
				if (row == 57 && v.i == 26)
						printf("57 26 tmp %d\n", v.tmp);
				v.i_min = v.i;
			}
			else
			{
				if ((v.tmp = pf_calc_dfs(data, v.i, path, index + 1)) < v.pmin
						&& (v.pmin = v.tmp))
					v.i_min = v.i;

				//pf_get_min(data->link_map[row] + v.i, v.tmp);
				if (row == 21 && v.i == 57)
						printf("21 57 tmp %d\n", v.tmp);
				if (data->link_map[row][v.i] >= v.tmp)
				{
					data->link_map[row][v.i] = v.tmp;
				}
				else
				{
				if (row == 21 && v.i == 57)
					printf("%d %d to 0\n", row, v.i);
					data->link_map[row][v.i] = 0;
				}
			}
			
		}
		v.i++;
	}
	if (v.i_min != data->lm_size + 1)
		path[index] = v.i_min;
	return (v.i_min == data->lm_size + 1 ? v.i_min : v.pmin + 1);
}

static int	pf_nbr_path(t_path **ppath)
{
	int		i;

	i = 0;
	while (ppath[i])
		i++;
	return (i);
}

int		li_resolve(t_data *data, t_path ***paths)
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
	path[0] = 0;
	pf_calc_dfs(data, 0, path, 1);
	pf_initpath(path, size);
	li_search_path(data, 0, path, p);
	ft_memdel((void **)&path);
	*paths = p;
	return (pf_nbr_path(p));
}
