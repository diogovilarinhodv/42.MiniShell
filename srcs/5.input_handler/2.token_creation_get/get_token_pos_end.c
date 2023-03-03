/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_pos_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:07:30 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/03 17:27:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	get_token_pos_end(t_data *data)
{
	while (ft_isspace(*(data->input.line + data->input.idx)) == 0
		&& *(data->input.line + data->input.idx) != '\0'
		&& *(data->input.line + data->input.idx) != '|'
		&& *(data->input.line + data->input.idx) != '&'
		&& *(data->input.line + data->input.idx) != '>'
		&& *(data->input.line + data->input.idx) != '<')
		data->input.idx++;
}
