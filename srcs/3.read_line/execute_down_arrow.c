/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_down_arrow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:35:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:26:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_down_arrow(t_data *data)
{
	char	*input;
	int		n;

	if (data->hist.idx < data->hist.qty_str)
		data->hist.idx++;
	if (data->hist.idx == data->hist.qty_str)
		input = "";
	else if (data->hist.idx > -1)
		input = *(data->hist.str + data->hist.idx);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	ft_bzero(data->input.buf, BUFSIZ);
	ft_strcpy(data->input.buf, input);
	n = write(STDOUT_FILENO, data->input.buf, ft_strlen(data->input.buf));
	data->input.buf_idx = n;
}
