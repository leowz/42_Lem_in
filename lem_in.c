/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:41 by zweng             #+#    #+#             */
/*   Updated: 2018/01/31 15:59:40 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
void	pf_data_del(t_data *dt)
{

}

void	pf_path_del(t_path *pt, int size)
{
	int 	i;

	if (pt)
	{
		i = 0;
		while (i < size)
		{
			free((pt + i)->path);
			(pt + i)->length = 0;
			free(pt + i);
			i++;
		}
		free(pt);
		pt = NULL;
	}
	size = 0;
}
*/
void	pf_init_data(t_data *dt)
{
	dt->ant_nbr = 0;
	dt->ls_rooms = NULL;
	dt->link_map = NULL;
	dt->lm_size = 0;
	dt->rm_names = NULL;
}

int		main(void)
{
	t_data	data;
	t_path	**paths;
	int		path_nbr;

	paths = NULL;
	pf_init_data(&data);
	if (!li_get_input(&data))
	{
		//ft_putstr_fd("ERROR\n", STDOUT_FILENO);
		return (1);
	}
//	print_tab(&data);
	ft_putstr("\n");
	if ((path_nbr = li_resolve(&data, &paths)))
	{
	//print paths;
		printf("before print path\n");
		print_paths(paths, &data);
		printf("after print path\n");
		li_print_res(&data, paths);
		printf("after print res\n");
	}
	//else
	//	ft_putstr_fd("ERROR\n", STDERR_FILENO);
	print_tab(&data);
	//pf_data_del(&data);
	//pf_path_del(paths, path_nbr);
	//li_find_path(data);
	return (0);
}
