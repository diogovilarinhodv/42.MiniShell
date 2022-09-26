/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/26 11:18:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_input(t_data *data)
{
	while (data->tmp.idx <= data->line.qty_pipes)
	{
		data->tmp.cmd = (data->line.cmd + data->tmp.idx);
		if (builtins(data) == NO)
			non_builtin(data);
		data->tmp.idx++;
	}
	data->tmp.idx = 0;
	data->tmp.cmd = NULL;
}
