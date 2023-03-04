/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:30:23 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/04 13:49:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	free_history(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->hist.str != NULL)
	{
		while (inc < data->hist.qty_str)
		{
			free(*(data->hist.str + inc));
			*(data->hist.str + inc) = NULL;
			inc++;
		}
		free(data->hist.str);
		data->hist.str = NULL;
	}
}

void	end_program(t_data *data, int exit_status)
{
	data->exit_status = exit_status;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->termcaps.old_term) == -1)
		data->exit_status = FAIL;
	free_env(data);
	free_input(data);
	free_table_all_fd(data);
	free_store(data);
	free_termcaps(data);
	free_history(data);
	exit(data->exit_status);
}
