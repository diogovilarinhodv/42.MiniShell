/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_termcaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:49:37 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:17:32 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_termcaps(t_data *data)
{
	char	*term_value;
	char	*buffer;

	buffer = NULL;
	if (tcgetattr(STDIN_FILENO, &data->termcaps.old_term) == -1)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
	term_value = get_env_value(data, "TERM");
	if (term_value == NULL)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
	if (tgetent(buffer, term_value) < 1)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
	data->termcaps.buffer = buffer;
	if (set_termcaps_config(data) == FAIL)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
}
