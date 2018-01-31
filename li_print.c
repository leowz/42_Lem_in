/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:13:10 by zweng             #+#    #+#             */
/*   Updated: 2018/01/26 16:16:55 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_putline(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
}
void	pf_init_ants(t_ant *ants, int size)
{
	int 	i = 0;
	while (i < size)
	{
		ants[i].n_room = -1;
		ants[i].n_path = -1;
		i++;
	}
}

void	li_print_res(t_data *data, t_path **paths)
{
	int		i = 0;
	int		j = 0;
	int		brk = 1;
	int		flag;

	t_ant	*ants = malloc(sizeof(t_ant) * data->ant_nbr);
	pf_init_ants(ants, data->ant_nbr);
	while (1)
	{
		i = 0;
		brk = 1;
		j = 0;
		flag = 0;
		//printf("print_res\n");
		while (i < data->ant_nbr && ants[i].n_room != -1)
		{
		//	printf("before alloc path\n");
		//	while (ants[i].n_room == -1 && paths[j] && i < data->lm_size)
		//	{
		//		ants[i].n_room = paths[j]->path[0];
		//		ants[i].n_path = j;
		//		i++;
		//		j++;
		//		brk = 0;
		//	}
			//print_ants(ants, data->lm_size);
		//	printf("before print one\n");
			if (ants[i].n_room != -1 && ants[i].n_room < paths[ants[i].n_path]->length)
			{
				int p_n = paths[ants[i].n_path]->path[ants[i].n_room];
				flag = 1;
				printf("L%d-%s ", i + 1, data->rm_names[p_n]);
			}
		//	printf("before update room\n");
			if (ants[i].n_room >= 0 && ants[i].n_room < data->lm_size)
			{
				brk = 0;
				ants[i].n_room++;
			}
			i++;
		}
	//	print_ants(ants, data->lm_size);
	//	printf("before alloc path i = %d\n",i);
			while (ants[i].n_room == -1 && paths[j] && i < data->ant_nbr)
			{
			//	printf("update ant %d\n", i);
				ants[i].n_room = 0;
				ants[i].n_path = j;
				i++;
				j++;
				brk = 0;
			}
			if (flag)
				printf("\n");
		if (brk)
			break ;
	}
}
