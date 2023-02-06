/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:15:34 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:36:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_another_table(t_data *data)
{
	int		inc;
	t_table	*clone;

	inc = 0;
	clone = malloc(sizeof(t_table) * (data->store.qty_tbl + 1));
	while (inc < data->store.qty_tbl)
	{
		(clone + inc)->cmd = (data->store.table + inc)->cmd;
		(clone + inc)->qty_cmd = (data->store.table + inc)->qty_cmd;
		(clone + inc)->delimiter = (data->store.table + inc)->delimiter;
		inc++;
	}
	(clone + inc)->cmd = NULL;
	(clone + inc)->qty_cmd = 0;
	(clone + inc)->delimiter = DELIMITER_NULL;
	if (data->store.table != NULL)
		free(data->store.table);
	data->store.table = clone;
	data->store.qty_tbl++;
}
