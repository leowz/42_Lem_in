/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:25:32 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:35:58 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_remain_ants(t_ant *ants, int i)
{
	int		j;

	j = 0;
	if (ants[i].n_room == -2 && ants[i].n_path == -2)
		return (0);
	while (ants[i + j].n_room != -2 && ants[i + j].n_path != -2)
		j++;
	return (j);
}

int		li_pt_flag(int flag)
{
	if ((flag & 1))
		ft_putstr("\n");
	if (!(flag & 2))
		return (0);
	return (1);
}

int		li_have_pathone(t_path **paths)
{
	while (paths && *paths)
	{
		if ((*paths)->length == 1)
			return (1);
		paths++;
	}
	return (0);
}

t_ant	*pf_new_ants(t_data *data)
{
	int		i;
	t_ant	*ants;

	i = 0;
	if (!(ants = malloc(sizeof(t_ant) * (data->ant_nbr + 1))))
		return (NULL);
	while (i < data->ant_nbr)
	{
		ants[i].n_room = -1;
		ants[i].n_path = -1;
		i++;
	}
	ants[i].n_room = -2;
	ants[i].n_path = -2;
	return (ants);
}

void	pf_increase(int *flag, int i, t_ant *ants)
{
	flag = 0;
	ants[i].n_room++;
}
