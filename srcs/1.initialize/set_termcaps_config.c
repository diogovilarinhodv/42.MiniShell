/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcaps_config.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:17:31 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/17 04:10:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	set_termcaps_config(t_data *data)
{
	data->termcaps.keys_on = tgetstr("ks", &data->termcaps.buffer);
	if (data->termcaps.keys_on)
		tputs(data->termcaps.keys_on, 1, ft_putint);
	data->termcaps.keys_off = tgetstr("ke", &data->termcaps.buffer);
	data->termcaps.up_arrow = tgetstr("ku", &data->termcaps.buffer);
	data->termcaps.down_arrow = tgetstr("kd", &data->termcaps.buffer);
	if (IS_LINUX)
		data->termcaps.backspace = tgetstr("kb", &data->termcaps.buffer);
	else
		data->termcaps.backspace = ft_strdup("\x7f");
	data->termcaps.del_line = tgetstr("dl", &data->termcaps.buffer);
	data->termcaps.set_cursor_begin = tgetstr("cr", &data->termcaps.buffer);
	if (data->termcaps.keys_on == NULL || data->termcaps.keys_off == NULL
		|| data->termcaps.up_arrow == NULL || data->termcaps.down_arrow == NULL
		|| data->termcaps.backspace == NULL || data->termcaps.del_line == NULL
		|| data->termcaps.set_cursor_begin == NULL)
		return (FAIL);
	return (SUCCESS);
}
