/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 13:55:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	organize(t_data *data)
{
	int		pos_beg;
	int		pos_end;
	char	*token;

	while (*(data->input.line + data->input.idx) != '\0')
	{
		get_tokens(data, &pos_beg, &pos_end);
		if (exist_token(data, pos_beg, pos_end) == END)
			break ;
		create_token(data, pos_beg, pos_end, &token);
		if (is_cmd_delimiter(token) == NO)
			add_token_to_cmd(data);
		if (is_cmd_delimiter(token) == YES)
			add_cmd_to_table(data);
		if (is_table_delimiter(token) == YES)
			add_table_to_data(data);
		/*
		if (is_pipe(token) == YES)
			data->table.qty_pipes++;
		if (is_first_cmd(data) == YES || is_pipe(token) == YES)
			add_cmd(data);
		if (is_pipe(token) == NO)
			add_token(data, token);
		*/
	}
	//testing_stuffs(data);
}
