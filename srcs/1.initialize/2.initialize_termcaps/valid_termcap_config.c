/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_termcap_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:24:19 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 13:44:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	valid_termcap_config(t_data *data)
{
	t_termcaps	var;

	var = data->termcaps;
	if (var.keys_on == NULL || var.keys_off == NULL)
		end_program(data, FAIL);
	if (var.up_arrow == NULL || var.down_arrow == NULL)
		end_program(data, FAIL);
	if (var.backspace == NULL)
		end_program(data, FAIL);
	if (var.del_line == NULL)
		end_program(data, FAIL);
	if (var.set_cursor_begin == NULL)
		end_program(data, FAIL);
}
