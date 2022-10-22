/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:39:44 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 12:59:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_cmd_to_table(t_data *data, t_cmd *cmd, t_table *table)
{
	if (table == NULL)
	{
		table = malloc(sizeof(t_table) * 1);
		table->cmd = &cmd;
		table->qty_cmd = 1;
	}
	else
	{
		*(table->cmd + table->qty_cmd) = &cmd;
		table->qty_cmd++;
	}
}