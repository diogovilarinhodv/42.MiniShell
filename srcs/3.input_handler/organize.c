/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:12:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	cmd_null(t_cmd *cmd)
{
	cmd = NULL;
}

static void	table_null(t_table *table)
{
	table = NULL;
}

// if token doesnt set, remove create_token and put what is inside, outside.

static int	token_creation(t_data *data, char *token)
{
	int		pos_beg;
	int		pos_end;

	get_tokens(data, &pos_beg, &pos_end);
	if (exist_token(data, pos_beg, pos_end) == END)
		return (FAIL);
	create_token(data, pos_beg, pos_end, &token);
	return (SUCCESS);
}

void	organize(t_data *data)
{
	char	*token;
	t_cmd	cmd;
	t_table	table;

	cmd_null(&cmd);
	table_null(&table);
	while (*(data->input.line + data->input.idx) != '\0')
	{
		if (token_creation(data, token) == FAIL)
			break ;
		if (is_cmd_delimiter(token) == NO)
			add_token_to_cmd(data, token, &cmd);
		if (is_cmd_delimiter(token) == YES)
		{
			add_cmd_to_table(data, &cmd, &table);
			cmd_null(&cmd);
		}
		if (is_table_delimiter(token) == YES)
		{
			add_table_to_data(data, &table);
			table_null(&table);
		}
		/*
		if (is_pipe(token) == YES)
			data->store.table->qty_pipes++;
		if (is_first_cmd(data) == YES || is_pipe(token) == YES)
			add_cmd(data);
		if (is_pipe(token) == NO)
			add_token(data, token);
		*/
	}
	//testing_stuffs(data);
}
