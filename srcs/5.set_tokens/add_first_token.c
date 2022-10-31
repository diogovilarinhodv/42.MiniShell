/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:04:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/31 12:15:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_token(t_data *data, char *token)
{
	data->cur.cmd->token = malloc(sizeof(char **) * (data->cur.cmd->qty_tkn + 1));
	*data->cur.cmd->token = token;
}