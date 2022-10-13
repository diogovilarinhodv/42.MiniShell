/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:45:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 09:54:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_dup2(t_data *data)
{
	if (data->tmp.idx < data->line.qty_pipes && data->line.qty_pipes > 0 && data->tmp.idx == 0)
		dup2(data->tmp.fd[data->tmp.idx][1], STDOUT_FILENO);
	else if (data->tmp.idx < data->line.qty_pipes && data->line.qty_pipes > 0)
	{
		dup2(data->tmp.fd[data->tmp.idx - 1][0], STDIN_FILENO);
		dup2(data->tmp.fd[data->tmp.idx][1], STDOUT_FILENO);
	}
	else if (data->tmp.idx == data->line.qty_pipes && data->line.qty_pipes > 0)
		dup2(data->tmp.fd[data->tmp.idx - 1][0], STDIN_FILENO);
	close_fds(data);
}