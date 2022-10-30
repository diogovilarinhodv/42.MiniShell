/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:04:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/30 23:20:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_token(t_data *data, char *token)
{
	((data->store.table + data->store.qty_tbl - 1)->cmd + (data->store.table + data->store.qty_tbl - 1)->qty_cmd - 1)->token = malloc(sizeof(char **) * (((data->store.table + data->store.qty_tbl - 1)->cmd + (data->store.table + data->store.qty_tbl - 1)->qty_cmd - 1)->qty_tkn + 2));
	*((data->store.table + data->store.qty_tbl - 1)->cmd + (data->store.table + data->store.qty_tbl - 1)->qty_cmd - 1)->token = token;
	*(((data->store.table + data->store.qty_tbl - 1)->cmd + (data->store.table + data->store.qty_tbl - 1)->qty_cmd - 1)->token + 1) = NULL;
}