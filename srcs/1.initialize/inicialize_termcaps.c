/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_termcaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:49:37 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 13:44:21 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_termcaps(t_data *data)
{
	char	*term_value;
	char	*buffer;

	buffer = NULL;
	if (tcgetattr(STDIN_FILENO, &data->termcaps.old_term) == -1)
		end_program(data, FAIL);
	term_value = get_env_value(data, "TERM");
	if (term_value == NULL)
		end_program(data, FAIL);
	if (tgetent(buffer, term_value) < 1)
		end_program(data, FAIL);
	data->termcaps.buffer = buffer;
	if (set_termcaps_config(data) == FAIL)
		end_program(data, FAIL);
}
