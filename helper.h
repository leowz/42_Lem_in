/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:13:27 by zweng             #+#    #+#             */
/*   Updated: 2018/01/26 16:16:53 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HP
# define HP
void	print_data(t_data *data);
void	print_names(t_data *data);
void	print_map(t_data *data);
void	print_size(t_data *data);
void	print_list(t_data *data);
void	print_tab(t_data *data);
void	print_path(t_path *pths);
void	print_paths(t_path **pth, t_data *data);
void	print_ant(t_ant *ant);
void	print_ants(t_ant *ant, int size);
#endif
