/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:22:52 by zweng             #+#    #+#             */
/*   Updated: 2018/02/08 22:21:08 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_RESOLVE_H
# define LI_RESOLVE_H

# include "lem_in.h"

typedef struct	s_var
{
	int			i;
	int			i_min;
	int			tmp;
	int			pmin;
}				t_var;

int				pf_contains(int *row, int n, int size);
void			pf_initpath(int *path, int size);
void			pf_init_va(t_var *va, int size);
int				pf_dfs(t_data *data, int row, int *arr);
void			li_path_sort(t_path **paths);
#endif
