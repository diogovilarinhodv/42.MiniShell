/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:37:16 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:03:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_redirection(t_data *data)
{
	data->cur.cmd->red = malloc(sizeof(t_red) * 1);
	data->cur.cmd->red->type = NO;
	data->cur.cmd->red->token = NULL;
	data->cur.cmd->is_red = YES;
	data->cur.cmd->qty_red = 1;
}
