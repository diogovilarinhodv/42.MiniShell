/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:29 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:11:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_token(t_data *data, char *token)
{
	if ((data->store.table->cmd + data->store.table->qty_cmd - 1)->qty_tkn == 0)
		add_first_token(data, token);
	else
		add_another_token(data, token);
	(data->store.table->cmd + data->store.table->qty_cmd - 1)->qty_tkn++;
}