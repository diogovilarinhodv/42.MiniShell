/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:21:07 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:36:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_redirection_token(t_data *data, char *token)
{
	(data->cur.cmd->red + data->cur.cmd->qty_red - 1)->token = token;
	data->cur.cmd->is_red = NO;
}
