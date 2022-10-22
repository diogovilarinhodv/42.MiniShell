/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:39:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:11:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_token_to_cmd(t_data *data, char *token, t_cmd *cmd)
{
	if (cmd == NULL)
	{
		cmd = malloc(sizeof(t_cmd) * 1);
		*cmd->token = token;
		cmd->qty_tkn = 1;data->store.table->cmd
	}
	else
	{
		*(cmd->token + cmd->qty_tkn) = token;
		cmd->qty_tkn++;
	}
}
