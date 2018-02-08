/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:25:55 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:35:50 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

int		pf_contains(int *row, int n, int size)
{
	int		i;

	i = 0;
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
	int i;

	i = 0;
	while (i < size)
		*(path + i++) = -1;
}

void	pf_init_va(t_var *va, int size)
{
	va->i = 0;
	va->i_min = size + 1;
	va->tmp = size + 1;
	va->pmin = size + 1;
}

void	li_path_sort(t_path **paths)
{
	int		i;
	int		j;
	t_path	*tmp;

	i = 0;
	while (paths && paths[i])
	{
		j = i + 1;
		while (paths[j])
		{
			if (paths[i]->length > paths[j]->length)
			{
				tmp = paths[i];
				paths[i] = paths[j];
				paths[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
