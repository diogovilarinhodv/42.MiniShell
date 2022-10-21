/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:04:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:44:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_token(t_data *data, char *token)
{
	(data->table.cmd + data->table.qty_cmd - 1)->token = malloc(sizeof(char **) * ((data->table.cmd + data->table.qty_cmd - 1)->qty_tkn + 2));
	*(data->table.cmd + data->table.qty_cmd - 1)->token = token;
	*((data->table.cmd + data->table.qty_cmd - 1)->token + 1) = NULL;
}