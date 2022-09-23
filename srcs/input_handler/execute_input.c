/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 15:15:21 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_input(t_data *data)
{
	int	inc;
	
	inc = 0;
	while (inc <= data->line.qty_pipes)
	{
		data->tmp.cmd = (data->line.cmd + inc);
		if (builtins(data) == NO)
			non_builtin(data);
		inc++;
	}
	data->tmp.cmd = NULL;
}
