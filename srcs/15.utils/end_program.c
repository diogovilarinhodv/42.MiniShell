/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:30:23 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/07 08:32:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

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
	exit(data->exit_status);
}
