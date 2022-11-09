/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 17:57:09 by dpestana         ###   ########.fr       */
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
		{
			if (is_first_cmd(data) == YES)
			{
				if (is_first_table(data) == YES)
					add_first_table(data);
				add_first_cmd(data);
			}
			if (is_redirection(data, token) == YES)
				add_redirection(data, token);
			else
				add_token(data, token);
		}
		else
		{
			if (is_table_delimiter(token) == YES)
				add_another_table(data);
			else
				add_another_cmd(data);
			free(token);
		}
	}
}
