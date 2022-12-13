/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:46:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:03:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_cmd(t_data *data)
{
	set_cur(data);
	data->cur.table->cmd = malloc(sizeof(t_cmd) * (data->cur.table->qty_cmd + 1));
	data->cur.table->qty_cmd++;
	data->cur.table->cmd->token = NULL;
	data->cur.table->cmd->qty_tkn = 0;
	data->cur.table->cmd->is_red = NO;
	data->cur.table->cmd->qty_red = 0;
	data->cur.table->cmd->red = NULL;
	unset_cur(data);
}
