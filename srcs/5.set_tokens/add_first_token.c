/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:04:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/05 17:01:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_token(t_data *data, char *token)
{
	data->cur.cmd->token = malloc(sizeof(char **) * (data->cur.cmd->qty_tkn + 2));
	*data->cur.cmd->token = token;
	*(data->cur.cmd->token + 1) = NULL;
}