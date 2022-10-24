/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:48:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 13:37:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_cmd) * ((data->store.table + data->store.qty_tbl - 1)->qty_cmd + 1));
	while (inc < (data->store.table + data->store.qty_tbl - 1)->qty_cmd)
	{
		(clone + inc)->token = ((data->store.table + data->store.qty_tbl - 1)->cmd + inc)->token;
		(clone + inc)->qty_tkn = ((data->store.table + data->store.qty_tbl - 1)->cmd + inc)->qty_tkn;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->qty_tkn = 0;
	if ((data->store.table + data->store.qty_tbl - 1)->cmd != NULL)
		free((data->store.table + data->store.qty_tbl - 1)->cmd);
	(data->store.table + data->store.qty_tbl - 1)->cmd = clone;
	(data->store.table + data->store.qty_tbl - 1)->qty_cmd++;
}