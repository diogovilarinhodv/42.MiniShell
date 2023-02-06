/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:55:55 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:36:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_first_table(t_data *data)
{
	data->store.table = malloc(sizeof(t_table) * (data->store.qty_tbl + 1));
	data->store.qty_tbl++;
	data->store.table->cmd = NULL;
	data->store.table->qty_cmd = 0;
	data->store.table->delimiter = DELIMITER_NULL;
}
