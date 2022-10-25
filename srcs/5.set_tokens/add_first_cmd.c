/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:46:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 11:38:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_cmd(t_data *data)
{
	(data->store.table + data->store.qty_tbl - 1)->qty_cmd = 1;
	(data->store.table + data->store.qty_tbl - 1)->cmd = malloc(sizeof(t_cmd) * (data->store.table + data->store.qty_tbl - 1)->qty_cmd);
	(data->store.table + data->store.qty_tbl - 1)->cmd->token = NULL;
	(data->store.table + data->store.qty_tbl - 1)->cmd->qty_tkn = 0;
}