/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:21:05 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 10:13:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void inicialize_cmd(t_data *data)
{
	data->line.cmd = malloc(sizeof(t_cmd) * 1);
	data->line.cmd->token = NULL;
	data->line.cmd->qty = 0;
}

void	inicialize_line(t_data *data)
{
    inicialize_cmd(data);
    data->line.qty_pipes = 0;
}