/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 18:27:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	get_str_pos_beg(t_data *data, int *inc)
{
	while (*(data->line + *inc) == ' ')
		(*inc)++;
	return (*inc);
}

static	int	get_str_pos_end(t_data *data, int *inc)
{
	while (*(data->line + *inc) != ' ' && *(data->line + *inc) != '\0')
		(*inc)++;
	return (*inc);
}

void	organize_line(t_data *data)
{
	int		inc;
	int		is_cmd;
	int		pos_beg;
	int		pos_end;

	inc = 0;
	is_cmd = 0;
	while (1)
	{
		pos_beg = get_str_pos_beg(data, &inc);
		// find '|'
		pos_end = get_str_pos_end(data, &inc);
		if (pos_beg == pos_end)
			break ;
		if (is_cmd == 0)
			set_cmd(data, &is_cmd, pos_beg, pos_end);
		else
			set_args(data, pos_beg, pos_end);
		if (*(data->line + inc) == '\0')
			break ;
	}
}
