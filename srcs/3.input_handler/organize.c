/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/16 19:58:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	organize(t_data *data)
{
	int		inc;
	int		pos_beg;
	int		pos_end;
	char	*token;

	inc = 0;
	while (*(data->input + inc) != '\0')
	{
		get_tokens(data, &inc, &pos_beg, &pos_end);
		if (exist_token(data, inc, pos_beg, pos_end) == END)
			break ;
		if(token_has_quotes(data, pos_beg, pos_end) == YES)
			remove_quotes(data, &pos_beg, &pos_end);
		create_token(data, pos_beg, pos_end, &token);
		if (is_pipe(token) == YES)
			data->line.qty_pipes++;
		if (is_first_cmd(data) == YES || is_pipe(token) == YES)
			add_cmd(data);
		if (is_pipe(token) == NO)
			add_token(data, token);
	}
	//testing_stuffs(data);
}
