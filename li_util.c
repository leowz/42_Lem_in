/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:57:14 by zweng             #+#    #+#             */
/*   Updated: 2018/02/09 20:41:21 by zweng            ###   ########.fr       */
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

void	li_putline(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
}

int		li_get_input(t_data *data)
{
	char	*line;
	int		flag;
	int		tmp;
	t_room	*lastroom;

	flag = 0;
	lastroom = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		li_putline(line);
		tmp = li_input_juge(data, line, &flag, &lastroom);
		ft_strdel(&line);
		if (tmp >= 0)
			continue ;
		else
			return (0);
	}
	ft_strdel(&line);
	if ((flag & F_RM) && (flag & F_LK) && (flag & F_LK_ALC))
		return (1);
	return (0);
}
