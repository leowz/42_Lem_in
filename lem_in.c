/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:41 by zweng             #+#    #+#             */
/*   Updated: 2018/02/09 20:30:35 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pf_data_del(t_data *dt)
{
	int		i;
	t_list	*node;
	t_list	*tmp;

	if (dt)
	{
		i = 0;
		node = dt->ls_rooms;
		while (node)
		{
			tmp = node->next;
			free(node->content);
			free(node);
			node = tmp;
		}
		while (i < dt->lm_size)
		{
			free(dt->link_map[i]);
			free((dt->rm_names)[i]);
			i++;
		}
		free(dt->rm_names);
		free(dt->link_map);
	}
}

void	pf_path_del(t_path **pt, int size)
{
	int		i;

	size = 0;
	if (pt)
	{
		i = 0;
		while (*(pt + i))
		{
			free((*(pt + i))->path);
			(*(pt + i))->length = 0;
			free(*(pt + i));
			i++;
		}
		free(pt);
	}
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
	{
		ft_putstr_fd("ERROR\n", STDOUT_FILENO);
		return (1);
	}
	pf_path_del(paths, path_nbr);
	pf_data_del(&data);
	return (0);
}
