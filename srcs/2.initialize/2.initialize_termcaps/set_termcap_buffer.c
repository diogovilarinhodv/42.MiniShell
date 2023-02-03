/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:02:27 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:03:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_buffer(t_data *data)
{
	char	*term_val;

	term_val = get_env_value(data, "TERM");
	if (term_val == NULL)
		end_program(data, FAIL);
	if (tgetent(data->termcaps.buffer, term_val) < 1)
		end_program(data, FAIL);
}
