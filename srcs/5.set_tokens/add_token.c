/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:29 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 12:56:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_token(t_data *data, char *token)
{
	if (((data->store.table + data->store.qty_tbl - 1)->cmd + (data->store.table + data->store.qty_tbl - 1)->qty_cmd - 1)->qty_tkn == 0)
		add_first_token(data, token);
	else
		add_another_token(data, token);
	((data->store.table + data->store.qty_tbl - 1)->cmd + (data->store.table + data->store.qty_tbl - 1)->qty_cmd - 1)->qty_tkn++;
}