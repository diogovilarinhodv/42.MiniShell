/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_stuffs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:04:23 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/15 16:29:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	testing_stuffs(t_data *data)
{
	int	inc_table;
	int inc_cmd;
	int	inc_tkn;
	int	inc_red;
	
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
		printf("-----------------\n");
		printf("--- Table[%d] ---\n", inc_table);
		printf("-----------------\n");
		printf("Total cmds: %d\n", (data->store.table + inc_table)->qty_cmd);
		inc_cmd = 0;
		while (inc_cmd < (data->store.table + inc_table)->qty_cmd)
		{
			printf("---------------\n");
			printf("--- CMD[%d] ---\n", inc_cmd);
			printf("---------------\n");
			printf("Total tokens: %d\n", ((data->store.table + inc_table)->cmd + inc_cmd)->qty_tkn);
			inc_tkn = 0;
			while (inc_tkn < ((data->store.table + inc_table)->cmd + inc_cmd)->qty_tkn)
			{
				printf("Table[%d], Cmd[%d], Token[%d] - %s\n", inc_table, inc_cmd, inc_tkn, *(((data->store.table + inc_table)->cmd + inc_cmd)->token + inc_tkn));
				inc_tkn++;
			}
			printf("Total redirects: %d\n", ((data->store.table + inc_table)->cmd + inc_cmd)->qty_red);
			inc_red = 0;
			while (inc_red < ((data->store.table + inc_table)->cmd + inc_cmd)->qty_red)
			{
				printf("Table[%d], Cmd[%d], Redirect[%d] - Type[%d] File[%s]\n", inc_table, inc_cmd, inc_red, (((data->store.table + inc_table)->cmd + inc_cmd)->red + inc_red)->type, (((data->store.table + inc_table)->cmd + inc_cmd)->red + inc_red)->token);
				inc_red++;
			}
			inc_cmd++;
		}
		inc_table++;
	}
	free_env(data);
	free_input(data);
	free_store(data);
	exit(0);
}