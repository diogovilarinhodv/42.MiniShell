/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:37:16 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:36:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_first_redirection(t_data *data)
{
	data->cur.cmd->red = malloc(sizeof(t_red) * 1);
	data->cur.cmd->red->type = NO;
	data->cur.cmd->red->token = NULL;
	data->cur.cmd->is_red = YES;
	data->cur.cmd->qty_red = 1;
}
