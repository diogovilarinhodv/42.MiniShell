/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 12:40:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	is_token_delimiter(char *token)
{
	if (*token == ';')
		return (YES);
	if (*token == '|')
		return (YES);
	if (*token == '&')
		return (YES);
	return (NO);
}

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
		if (is_token_delimiter(token) == YES)
		{
			
		}
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
