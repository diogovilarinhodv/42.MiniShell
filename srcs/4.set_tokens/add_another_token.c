/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:05:24 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:44:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_token(t_data *data, char *token)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * ((data->table.cmd + data->table.qty_cmd - 1)->qty_tkn + 2));
	while (inc < (data->table.cmd + data->table.qty_cmd - 1)->qty_tkn)
	{
		*(clone + inc) = *((data->table.cmd + data->table.qty_cmd - 1)->token + inc);
		inc++;
	}
	*(clone + inc) = token;
	*(clone + inc + 1) = NULL;
	if ((data->table.cmd + data->table.qty_cmd - 1)->token != NULL)
		free((data->table.cmd + data->table.qty_cmd - 1)->token);
	(data->table.cmd + data->table.qty_cmd - 1)->token = clone;
}