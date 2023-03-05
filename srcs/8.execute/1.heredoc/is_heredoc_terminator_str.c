/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc_terminator_str.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:52:23 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 14:55:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_heredoc_terminator_str(t_data *data)
{
	*(data->input.buf + data->input.buf_idx - 1) = '\0';
	if (ft_strcmp(data->input.buf, data->cur.cmd->red->token) == 0)
		return (YES);
	*(data->input.buf + data->input.buf_idx - 1) = '\n';
	*(data->input.buf + data->input.buf_idx) = '\0';
	return (NO);
}
