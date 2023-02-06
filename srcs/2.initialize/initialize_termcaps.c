/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_termcaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:49:37 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 14:17:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_termcaps(t_data *data)
{
	data->termcaps.backspace = NULL;
	data->termcaps.buffer = NULL;
	data->termcaps.del_line = NULL;
	data->termcaps.up_arrow = NULL;
	data->termcaps.down_arrow = NULL;
	data->termcaps.keys_off = NULL;
	data->termcaps.keys_on = NULL;
	data->termcaps.set_cursor_begin = NULL;
	set_termcap_old_term(data);
	set_termcap_buffer(data);
	set_termcap_keys_on_off(data);
	set_termcap_keys_up_down(data);
	set_termcap_backspace(data);
	set_termcap_delete(data);
	set_termcap_cursor(data);
	valid_termcap_config(data);
}
