/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:46:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/08 15:21:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_first_cmd(t_data *data)
{
	int	qty;

	set_cur(data);
	qty = (data->cur.table->qty_cmd + 1);
	data->cur.table->cmd = malloc(sizeof(t_cmd) * qty);
	data->cur.table->qty_cmd++;
	data->cur.table->cmd->token = NULL;
	data->cur.table->cmd->qty_tkn = 0;
	data->cur.table->cmd->is_red = NO;
	data->cur.table->cmd->qty_red = 0;
	data->cur.table->cmd->red = NULL;
	data->cur.table->cmd->is_heredoc = NO;
	data->cur.table->cmd->pid = 0;
	data->cur.table->cmd->is_builtin = NO;
	unset_cur(data);
}
