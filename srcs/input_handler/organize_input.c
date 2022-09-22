/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/22 16:01:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	get_str_pos_beg(t_data *data, int *inc)
{
	while (*(data->input + *inc) == ' ')
		(*inc)++;
	return (*inc);
}

static	int	get_str_pos_end(t_data *data, int *inc)
{
	while (*(data->input + *inc) != ' ' && *(data->input + *inc) != '\0' && *(data->input + *inc) != '|')
		(*inc)++;
	return (*inc);
}

void	organize_input(t_data *data)
{
	int		inc;
	int		has_pipe;
	int		pos_beg;
	int		pos_end;

	inc = 0;
	has_pipe = 0;
	while (1)
	{
		pos_beg = get_str_pos_beg(data, &inc);
		if (*(data->input + inc) != '|')
		{
			has_pipe = 1;
			pos_beg = get_str_pos_beg(data, &inc);
			if (has_pipe == 1 && *(data->input + inc) != '|')
				break ;
		}
		pos_end = get_str_pos_end(data, &inc);
		if (pos_beg == pos_end && *(data->input + inc) == '\0' || pos_beg == pos_end && *(data->input + inc) != '|')
			break ;
		set_cmd(data, has_pipe, pos_beg, pos_end);
		has_pipe = 0;
		if (*(data->input + inc) == '\0')
			break ;
	}
}
