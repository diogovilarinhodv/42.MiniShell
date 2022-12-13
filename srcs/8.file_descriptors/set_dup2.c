/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:45:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:12:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_dup2(t_data *data)
{
	if (is_only_one_cmd_fd(data) == YES)
		return ;
	if (is_first_cmd_fd(data) == YES)
	{
		dup2(data->cur.table->fd[data->cur.idx_cmd][1], STDOUT_FILENO);
	}
	else if (is_middle_cmd_fd(data) == YES)
	{
		dup2(data->cur.table->fd[data->cur.idx_cmd - 1][0], STDIN_FILENO);
		dup2(data->cur.table->fd[data->cur.idx_cmd][1], STDOUT_FILENO);
	}
	else if (is_last_cmd_fd(data) == YES)
	{
		dup2(data->cur.table->fd[data->cur.idx_cmd - 1][0], STDIN_FILENO);
	}
}
