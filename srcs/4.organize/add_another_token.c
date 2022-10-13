/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:05:24 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 20:28:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_token(t_data *data, char *token)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * ((data->line.cmd + data->line.qty_cmd - 1)->qty_tkn + 2));
	while (inc < (data->line.cmd + data->line.qty_cmd - 1)->qty_tkn - 1)
	{
		*(clone + inc) = *((data->line.cmd + data->line.qty_cmd - 1)->token + inc);
		inc++;
	}
	*(clone + inc) = token;
	*(clone + inc + 1) = NULL;
	if ((data->line.cmd + data->line.qty_cmd - 1)->token != NULL)
		free((data->line.cmd + data->line.qty_cmd - 1)->token);
	(data->line.cmd + data->line.qty_cmd - 1)->token = clone;
}