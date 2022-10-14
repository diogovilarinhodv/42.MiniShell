/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_stuffs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:04:23 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/14 20:51:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	testing_stuffs(t_data *data)
{
	int inc_cmd;
	int	inc_tkn;
	
	inc_cmd = 0;
	inc_tkn = 0;
	if (data->line.cmd == NULL)
		return ;
	if (data->line.cmd->token == NULL)
		return ;
	printf("Total cmds: %d\n", data->line.qty_cmd);
	while (inc_cmd < data->line.qty_cmd)
	{
		while (inc_tkn < (data->line.cmd + inc_cmd)->qty_tkn)
		{
			printf("Token[%d] - [%s]\n", inc_tkn, *((data->line.cmd + inc_cmd)->token + inc_tkn));
			inc_tkn++;
		}
		printf("cmd[%d] - Total Tokens: %d\n", inc_cmd, (data->line.cmd + inc_cmd)->qty_tkn);
		inc_tkn = 0;
		if (inc_cmd + 1 == data->line.qty_cmd)
			printf ("\n");
		inc_cmd++;
	}
}