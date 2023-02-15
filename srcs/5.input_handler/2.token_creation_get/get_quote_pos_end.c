/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_pos_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:25:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/15 16:00:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

static void	single_quote_pos_end(t_data *data)
{
	int	len;

	len = 0;
	data->input.idx++;
	len = ft_strlen(data->input.line);
	while (data->input.idx < len)
	{
		if (*(data->input.line + len) == '\'')
			break ;
		len--;
	}
	data->input.idx = len + 1;
}

static void	double_quote_pos_end(t_data *data)
{
	int	len;

	len = 0;
	data->input.idx++;
	len = ft_strlen(data->input.line);
	while (data->input.idx < len)
	{
		if (*(data->input.line + len) == '"')
			break ;
		len--;
	}
	data->input.idx = len + 1;
}

void	get_quote_pos_end(t_data *data)
{
	if (*(data->input.line + data->input.idx) == '"')
		double_quote_pos_end(data);
	else if (*(data->input.line + data->input.idx) == '\'')
		single_quote_pos_end(data);
}
