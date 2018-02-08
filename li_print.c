/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:13:10 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:36:01 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	pf_distribute_ants(t_ant *ants, int *i, t_path **paths, int *flag)
{
	int		ants_remain;
	int		j;

	j = 0;
	ants_remain = li_remain_ants(ants, *i);
	while (ants_remain > 0 && paths[j])
	{
		if (j == 0 || (ants_remain - (paths[j]->length - paths[j - 1]->length))
				> 0)
		{
			ants[*i].n_room = 0;
			ants[*i].n_path = j;
			ants_remain--;
			(*i)++;
			j++;
		}
		else
			break ;
	}
	if (!(*flag & 2))
		*flag += 2;
}

static void	pf_print_one(t_data *data, int i, int *flag, int p_n)
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

static void	pf_print_pathone(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->ant_nbr)
	{
		ft_putstr("L");
		ft_putnbr(i + 1);
		ft_putstr("-");
		ft_putstr(data->rm_names[data->lm_size - 1]);
		if (i < data->ant_nbr - 1)
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

static void	pf_print_ants(t_data *data, t_ant *ants, t_path **paths)
{
	int		i;
	int		flag;

	while (1)
	{
		i = 0;
		flag = 0;
		while (i < data->ant_nbr && ants[i].n_room != -1)
		{
			if (ants[i].n_room != -1 && ants[i].n_room <
					paths[ants[i].n_path]->length)
				pf_print_one(data, i, &flag,
						paths[ants[i].n_path]->path[ants[i].n_room]);
			if (ants[i].n_room >= 0 && ants[i].n_room < data->lm_size)
				pf_increase(&flag, i, ants);
			i++;
		}
		if (ants[i].n_room == -1 && i < data->ant_nbr)
			pf_distribute_ants(ants, &i, paths, &flag);
		if (!li_pt_flag(flag))
			return ;
	}
}

void		li_print_res(t_data *data, t_path **paths)
{
	t_ant	*ants;

	if (li_have_pathone(paths))
	{
		pf_print_pathone(data);
		return ;
	}
	if (!(ants = pf_new_ants(data)))
		return ;
	pf_print_ants(data, ants, paths);
	ft_memdel((void **)&ants);
	ants = NULL;
}
