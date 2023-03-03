/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/03 17:31:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

static int	is_that_char(char ch)
{
	if (ch == '|' | ch == '&' | ch == '<' | ch == '>')
		return (YES);
	return (NO);
}

static void	get_token_pos_end_special(t_data *data)
{
	while (is_that_char(*(data->input.line + data->input.idx)) == YES)
		data->input.idx++;
}

void	get_tokens(t_data *data, int *pos_beg, int *pos_end)
{
	get_token_pos_begin(data);
	*pos_beg = data->input.idx;
	if (is_quote(data) == YES)
		get_quote_pos_end(data);
	else if (is_that_char(*(data->input.line + *pos_beg)) == NO)
		get_token_pos_end(data);
	else
		get_token_pos_end_special(data);
	*pos_end = data->input.idx;
	while (*(data->input.line + data->input.idx) == ' ')
		data->input.idx++;
}
