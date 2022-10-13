/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:29 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 20:21:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_token(t_data *data, char *token)
{
	if (data->line.qty_cmd == 0)
		add_cmd(data);
	if ((data->line.cmd + data->line.qty_cmd - 1)->qty_tkn == 0)
		add_first_token(data, token);
	else
		add_another_token(data, token);
	(data->line.cmd + data->line.qty_cmd - 1)->qty_tkn++;
}