/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_pos_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:25:40 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:01:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	get_quote_pos_end(t_data *data)
{
	if (*(data->input.line + data->input.idx) == '"')
	{
		data->input.idx++;
		while (*(data->input.line + data->input.idx) != '"')
			data->input.idx++;
		data->input.idx++;
	}
	else if (*(data->input.line + data->input.idx) == '\'')
	{
		data->input.idx++;
		while (*(data->input.line + data->input.idx) != '\'')
			data->input.idx++;
		data->input.idx++;
	}
}
