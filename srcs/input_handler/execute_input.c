/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/04 12:57:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	execute_input_clean(t_data *data)
{
	int	inc;

	inc = 0;
	close(data->tmp.fd[0]);
	close(data->tmp.fd[1]);
	while (inc <= data->line.qty_pipes)
	{
		waitpid(*(data->tmp.pid + inc), NULL, 0);
		inc++;
	}
}

void	execute_input(t_data *data)
{
	data->tmp.pid = malloc(sizeof(int) * (data->line.qty_pipes + 1));
	while (data->tmp.idx <= data->line.qty_pipes)
	{
		*(data->tmp.pid + data->tmp.idx) = fork();
		if (*(data->tmp.pid + data->tmp.idx) == 0)
		{
			data->tmp.cmd = (data->line.cmd + data->tmp.idx);
			if (builtins(data) == NO)
				non_builtin(data);
		}
		data->tmp.idx++;
	}
	execute_input_clean(data);
}
