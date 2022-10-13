/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:44:51 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 19:51:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_cmd(t_data *data)
{
	if (data->line.qty_cmd == 0)
		add_first_cmd(data);
	else
		add_another_cmd(data);
	data->line.qty_cmd++;
}