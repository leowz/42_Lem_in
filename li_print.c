/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:13:10 by zweng             #+#    #+#             */
/*   Updated: 2018/02/01 17:07:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant	*pf_new_ants(t_data *data)
{
	int 	i;
	t_ant	*ants;

	if (!(ants = malloc(sizeof(t_ant) * data->ant_nbr)))
			return (NULL);
	i = 0;
	while (i < data->ant_nbr)
	{
		ants[i].n_room = -1;
		ants[i].n_path = -1;
		i++;
	}
	return (ants);
}

static void	pf_distribute_ants(t_ant *ants, int *i, int *j, int *flag)
{			
	ants[*i].n_room = 0;
	ants[*i].n_path = *j;
	(*i)++;
	(*j)++;
	if (!(*flag & 2))
		*flag += 2;
}

static void pf_print_one(t_data *data, int i, int *flag, int p_n)
{
	if (!(*flag & 1))
		*flag += 1;
	if ((*flag & 4))
		ft_putstr(" ");
	else
		*flag += 4;
	ft_putstr("L");
	ft_putnbr(i + 1);
	ft_putstr("-");
	ft_putstr(data->rm_names[p_n]);
	if (!(*flag & 2))
		*flag += 2;
}

static void pf_increase(int *flag, int i, t_ant *ants)
{
	flag = 0;
	ants[i].n_room++;
}

int		li_pt_flag(int flag)
{
	if ((flag & 1))
		ft_putstr("\n");
	if (!(flag & 2))
		return (0);
	return (1);
}
void	li_print_res(t_data *data, t_path **paths)
{
	int		i;
	int		j;
	int		flag;
	t_ant	*ants;
	
	if (!(ants = pf_new_ants(data)))
		return ;
	while (1)
	{
		i = 0;
		j = 0;
		flag = 0;
		while (i < data->ant_nbr && ants[i].n_room != -1)
		{
			if (ants[i].n_room != -1 && ants[i].n_room < paths[ants[i].n_path]->length)
				pf_print_one(data, i, &flag, paths[ants[i].n_path]->path[ants[i].n_room]);
			if (ants[i].n_room >= 0 && ants[i].n_room < data->lm_size)
				pf_increase(&flag, i, ants);
			i++;
		}
		while (ants[i].n_room == -1 && paths[j] && i < data->ant_nbr)
			pf_distribute_ants(ants, &i, &j, &flag);
		if (!li_pt_flag(flag))
			return ;
	}
}
