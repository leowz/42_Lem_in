/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:57:14 by zweng             #+#    #+#             */
/*   Updated: 2018/01/22 17:12:58 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_strccount(char *str, char c)
{
	int		ret;

	ret = 0;
	while (str && *str)
	{
		if (*str++ == c)
			ret++;
	}
	return (ret);
}

int		li_coord_isdigit(char *str)
{
	if (str && *str == ' ')
	{
		str++;
		while (*str && *str != ' ' && ft_isdigit(*str))
			str++;
		if (*str == 0 || *str == ' ')
			return (1);
	}
	return (0);
}
