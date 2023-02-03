/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:37:23 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 13:43:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_char(t_data *data, int *bytes_readed)
{
	*bytes_readed = read(STDIN_FILENO, (data->input.buf + data->input.buf_idx), BUFSIZ - data->input.buf_idx);
	if (is_arrow(data))
		select_history_cmd(data);
	else if (is_backspace(data) == YES)
		delete_char(data);
	else if (is_ctrl(data, *bytes_readed) == YES)
		ft_bzero((data->input.buf + data->input.buf_idx), BUFSIZ - data->input.buf_idx);
	else if (is_ctrl_c(data) == YES)
		reset_line(data);
	else if (is_ctrl_d(data) == YES)
		end_program(data, SUCCESS);
	else
		data->input.buf_idx += write(STDOUT_FILENO, (data->input.buf + data->input.buf_idx), *bytes_readed);
}
