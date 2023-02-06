/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	get_tokens(t_data *data, int *pos_beg, int *pos_end)
{
	get_token_pos_begin(data);
	*pos_beg = data->input.idx;
	if (is_quote(data) == YES)
		get_quote_pos_end(data);
	else
		get_token_pos_end(data);
	*pos_end = data->input.idx;
	if (*(data->input.line + data->input.idx) != '\0')
		data->input.idx++;
}
