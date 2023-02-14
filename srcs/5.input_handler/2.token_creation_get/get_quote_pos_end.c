/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_pos_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:25:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/14 11:15:00 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	get_quote_pos_end(t_data *data)
{
	int	len;

	len = 0;
	if (*(data->input.line + data->input.idx) == '"')
	{
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
	else if (*(data->input.line + data->input.idx) == '\'')
	{
		data->input.idx++;
		len = ft_strlen(data->input.line);
		while (data->input.idx < len)
		{
			if (*(data->input.line + len) == '\'')
				break ;
			len--;
		}
		data->input.idx++;
	}
}
