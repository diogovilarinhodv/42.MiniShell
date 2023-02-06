/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:05:24 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:36:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_another_token(t_data *data, char *token)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * (data->cur.cmd->qty_tkn + 2));
	while (inc < data->cur.cmd->qty_tkn)
	{
		*(clone + inc) = *(data->cur.cmd->token + inc);
		inc++;
	}
	*(clone + inc) = token;
	*(clone + inc + 1) = NULL;
	if (data->cur.cmd->token != NULL)
		free(data->cur.cmd->token);
	data->cur.cmd->token = clone;
}
