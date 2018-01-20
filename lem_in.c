/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:41 by zweng             #+#    #+#             */
/*   Updated: 2018/01/20 22:26:45 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "helper.h"

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

	pf_init_data(&data);
	if (!li_get_input(&data))
	{//!li_check_input(&data)
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		return (1);
	}
	print_data(&data);
	//li_find_path(data);
	return (0);
}
