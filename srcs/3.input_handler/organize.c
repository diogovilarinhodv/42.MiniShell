/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:00:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*cmd_limiter_run(t_data *data, char *token)
{
	if (is_first_cmd(data) == YES)
	{
		if (is_first_table(data) == YES)
			add_first_table(data);
		add_first_cmd(data);
	}
	set_cur(data);
	if (is_redirection(token) == YES)
		add_redirection_type(data, token);
	else if (data->cur.cmd->is_red == YES)
		add_redirection_token(data, token);
	else
		add_token(data, token);
	unset_cur(data);
	return (token);
}

static char	*non_cmd_limiter_run(t_data *data, char *token)
{
	if (is_table_delimiter(token) == YES)
		add_another_table(data);
	else
		add_another_cmd(data);
	free(token);
	return (token);
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
		if (is_cmd_delimiter(token) == NO)
			token = cmd_limiter_run(data, token);
		else
			token = non_cmd_limiter_run(data, token);
	}
}
