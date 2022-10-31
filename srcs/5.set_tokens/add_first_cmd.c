/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:46:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/31 10:45:37 by dpestana         ###   ########.fr       */
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
	unset_cur(data);
}