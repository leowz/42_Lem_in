/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:03:27 by zweng             #+#    #+#             */
/*   Updated: 2018/01/24 16:59:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	print_size(t_data *data)
{
	printf("#-----------------print size-------------#\n");
	printf("ant size is %d, lm_siz is %d\n", data->ant_nbr, data->lm_size);
	printf("#-----------------print size-------------#\n");
}

void	print_map(t_data *data)
{	
	int i;
	i = 0;
	
	printf("#-----------------link map %d * %d -------------#\n", data->lm_size, data->lm_size);
	while (i < data->lm_size)
	{
		int j = 0;
		while (j < data->lm_size)
		{
			printf("%-5d  ", data->link_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("#-----------------link map %d * %d -------------#\n", data->lm_size, data->lm_size);
}

void	print_tab(t_data *data)
{	
	int i;
	i = 0;
	
	printf("#-----------------tab%d * %d -------------#\n", data->lm_size, data->lm_size);
		int j = 0;
		printf("%-3c| ", ' ');
		while (j < data->lm_size)
		{
			printf("%-3.3s ", data->rm_names[j]);
			j++;
		}
		printf("\n");
		printf("%-3c| ", ' ');
		j = 0;
		while (j < data->lm_size)
		{
			printf("%-3d ", j);
			j++;
		}
		printf("\n");
	printf("#-----------------tab-------------#\n");
		printf("%-3d| ", 0);
	while (i < data->lm_size)
	{
		j = 0;
		while (j < data->lm_size)
		{
			printf("%-3d ", data->link_map[i][j]);
			j++;
		}
		printf("\n");
		if (i != data->lm_size -1)
			printf("%-3d| ", i + 1);
		i++;
	}
	printf("#-----------------tab%d * %d -------------#\n", data->lm_size, data->lm_size);
}

void	print_names(t_data *data)
{
	printf("#-----------------names-------------#\n");
		int j = 0;
		while (j < data->lm_size)
		{
			printf("%-5s  ", data->rm_names[j]);
			j++;
		}
		printf("\n");
	printf("#----------------names--------------#\n");
	
}

void	print_list(t_data *data)
{
	t_list *node = data->ls_rooms;

	printf("#----------------rooms--------------#\n");
	while (node)
	{
		printf("(%s) =>\n", ((t_room *)node->content)->name);	
		node = node->next;
	}
	printf("\n");
	printf("#----------------rooms--------------#\n");
}

void	print_data(t_data *data)
{
	print_size(data);
	print_names(data);
	print_map(data);
}
