/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 14:57:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	get_token_pos_end(t_data *data, int *inc)
{
	while (ft_isspace(*(data->input + *inc)) == 0 && *(data->input + *inc) != '\0' && *(data->input + *inc) != '|')
		(*inc)++;
	return (*inc);
}

int	organize_input(t_data *data)
{
	int		inc;
	int		has_pipe;
	int		pos_beg;
	int		pos_end;

	inc = 0;
	has_pipe = 0;
	while (1)
	{
		while(ft_isspace(*(data->input + inc)) == 1)
			inc++;
		pos_beg = inc;
		pos_end = get_token_pos_end(data, &inc);
		//printf ("%c - %c - %c <;> %d - %d - %d <;> %d\n", *(data->input + pos_beg),  *(data->input + pos_end), *(data->input + inc), pos_beg, pos_end, inc, has_pipe);
		if (!(pos_beg == pos_end && *(data->input + inc) == '|'))
		{
			set_cmd(data, has_pipe, pos_beg, pos_end);
			has_pipe = 0;
		}
		if (*(data->input + inc) == '|')
		{
			has_pipe++;
			inc++;
		}
		if (has_pipe > 1)
			return (FAIL);
		if (*(data->input + inc) == '\0')
			return (SUCCESS);
	}
	if (has_pipe > 0 || data->line.cmd == NULL)
		return (FAIL);
}
