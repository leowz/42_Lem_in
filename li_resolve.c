/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:53:01 by zweng             #+#    #+#             */
/*   Updated: 2018/01/24 18:23:08 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pf_print_path(int *path, int size)
{
	int i = 0;
	while (i < size && *(path + i) != -1)
	{
		ft_putnbr(*(path + i));
		ft_putstr(" --> ");
		i++;
	}
	ft_putstr("  finish\n");
}

int		pf_path_contains(int *row, int n, int size)
{
	int 	i = 0;
	//ft_putstr("enter path contains\n");
	while (*(row + i) != -1 && i < size)
	{
	//	ft_putstr("enter path contain boucle\n");
		if (*(row + i) == n)
		{
		//ft_putstr("enter path contain success\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void pf_zero(int **map, int row, int size)
{
	int 	i = 0;

	while (i < size && row != size - 1)
	{
		map[i][row] = 0;
		map[row][i] = 0;
		i++;
	}
}

int		pf_dfs(int **map, int row_nbr, int size, int *path, int index)
{
	int		i = 0;
	int		*row = map[row_nbr];
	int		ret = size;
	int		tmp = size;
	int		i_min = size;

//	printf("in dfs\n");
	if (row_nbr == size - 1)
		return (1);
	while (i < size)
	{
		if (row[i] != 0)
		{
			if (!pf_path_contains(path, i, index))
			{
				path[index] = i;
				if ((tmp = pf_dfs(map, i, size, path, index + 1)))
				{
					if (tmp < ret)
					{
						ret = tmp;
						i_min = i;
					}
				}
			}
		}
		i++;
	}
	if (i_min == size)
		return (size + 1);
	path[index] = i_min;
	map[i_min][row_nbr] = 0;
	map[row_nbr][i_min] = 0;
	return (ret + 1);
}

void	pf_initpath(int *path, int size)
{
	int i = 0;
	while (i < size)
		*(path + i++) = -1;
}
int 	gc = 0;

int		pf_calc_dfs(int **map, int size, int row, int *path, int index)
{
	int 	i = 0;
	int		i_min = size + 1;
	int		tmp = size + 1;
	int		pmin = size + 1;

	gc++;
	if (row == size - 1)
		return (1);
	while (i < size)
	{
		if (map[row][i] != 0 && !pf_path_contains(path, i, index))
		{
			path[index] = i;
			if (map[row][i] < size + 1 && map[row][i] != 0 && map[row][i] < pmin)
			{
				pmin = map[row][i];
				i_min = i;
			}
			else
			{
				tmp = pf_calc_dfs(map, size, i, path, index + 1);
				if (map[row][i] > tmp)
				{
					map[row][i] = tmp;
					map[i][row] = tmp;
				}
				else if (tmp == size + 1)
				{
					map[row][i] = 0;
					map[i][row] = 0;
				}
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

int		li_resolve(int **map, int size, t_path **paths)
{
	int		*path;
//	int		i = 0;
//	int		length;

	paths = NULL;
	path = malloc(sizeof(int) * (size + 1));
	pf_initpath(path, size);
/*	while (i < size)
	{
		path[0] = 0;
		if (map[0][i] == 1)
		{	
			path[1] = i;
			if (pf_dfs(map, i, size, path, 2))
				pf_print_path(path, size);
			//printf("find path start i = %d\n", i);
			pf_initpath(path, size);
		}
		i++;
	}
	*/
	path[0] = 0;
	//if ((length = pf_dfs(map, i, size, path, 1)) != size + 1)
	{
	//	printf("dfs find a path\n");
	//	pf_print_path(path, length);
//		printmap(map, size);
	//	printf("init path, length is %d\n", length);
		//pf_initpath(path, size);
		//path[0] = 0;
	}
	//pf_print_path(path);
	
	pf_calc_dfs(map, size, 0, path, 1);
	printf("gc is %d", gc);
	return (1);
}
