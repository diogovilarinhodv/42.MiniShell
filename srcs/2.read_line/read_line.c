/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:55:34 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:20:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_line(t_data *data)
{
	int		bytes_readed;

	turn_off_canonical(data);
	write_prompt(data);
	data->hist.idx = data->hist.qty_str;
	initialize_input(data);
	while (ft_strchr(data->input.buf, '\n') == NULL)
	{
		bytes_readed = read(STDIN_FILENO, (data->input.buf + data->input.buf_idx), BUFSIZ - data->input.buf_idx);
		if (is_arrow(data))
			select_history_cmd(data);
		else if (is_backspace(data) == YES)
			delete_char(data);
		else if (is_ctrl(data, bytes_readed) == YES)
			ft_bzero((data->input.buf + data->input.buf_idx), BUFSIZ - data->input.buf_idx);
		else if (is_ctrl_c(data) == YES)
			reset_line(data);
		else if (is_ctrl_d(data) == YES)
		{
			data->exit_status = SUCCESS;
			end_program(data);
		}
		else
			data->input.buf_idx += write(STDOUT_FILENO, (data->input.buf + data->input.buf_idx), bytes_readed);
	}
	data->input.line = get_input_str(data);
	if (data->input.line == NULL)
		if (*data->input.line == '\0')
			return ;
	add_line_to_history(data);
}
