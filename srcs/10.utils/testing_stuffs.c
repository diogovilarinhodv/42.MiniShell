/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_stuffs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:04:23 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:11:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	testing_stuffs(t_data *data)
{
	int	inc_table;
	int inc_cmd;
	int	inc_tkn;
	
	if (data->store.table == NULL)
		return ;
	if (data->store.table->cmd == NULL)
		return ;
	if (data->store.table->cmd->token == NULL)
		return ;
	printf("Total tables: %d\n", data->store.qty_tbl);
	inc_table = 0;
	while (inc_table < data->store.qty_tbl)
	{
		printf("Total cmds: %d\n", (data->store.table + inc_table)->qty_cmd);
		inc_cmd = 0;
		while (inc_cmd < (data->store.table + inc_table)->qty_cmd)
		{
			printf("Total tokens: %d\n", ((data->store.table + inc_table)->cmd + inc_cmd)->qty_tkn);
			inc_tkn = 0;
			while (inc_tkn < ((data->store.table + inc_table)->cmd + inc_cmd)->qty_tkn)
			{
				printf("Table[%d], Cmd[%d], Token[%d] - %s\n", inc_table, inc_cmd, inc_tkn, *(((data->store.table + inc_table)->cmd + inc_cmd)->token + inc_tkn));
				inc_tkn++;
			}
			inc_cmd++;
		}
		inc_table++;
	}
}