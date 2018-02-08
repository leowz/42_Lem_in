/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:41 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:36:02 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pf_del_room(void *p, size_t size)
{
	t_room	*rm;

	rm = p;
	size = 0;
	ft_strdel(&(rm->name));
	rm->x = 0;
	rm->y = 0;
	free(p);
}

void	pf_data_del(t_data *dt)
{
	int		i;

	if (dt)
	{
		i = 0;
		ft_lstdel(&(dt->ls_rooms), pf_del_room);
		while (i < dt->lm_size)
		{
			ft_memdel((void **)&(dt->link_map[i]));
			i++;
		}
		ft_memdel((void **)&(dt->rm_names));
		ft_memdel((void **)&(dt->link_map));
	}
}

void	pf_path_del(t_path **pt, int size)
{
	int		i;

	if (pt)
	{
		i = 0;
		while (i < size)
		{
			free(pt[i]->path);
			pt[i]->length = 0;
			free(pt[i]);
			i++;
		}
		free(pt);
		pt = NULL;
	}
	size = 0;
}

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
		ft_putstr_fd("ERROR\n", STDOUT_FILENO);
		return (1);
	}
	ft_putstr("\n");
	if ((path_nbr = li_resolve(&data, &paths)))
		li_print_res(&data, paths);
	else
		ft_putstr_fd("ERROR\n", STDOUT_FILENO);
	pf_data_del(&data);
	pf_path_del(paths, path_nbr);
	return (0);
}
