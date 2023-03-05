/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_read_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:24:32 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 16:33:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	read_char_heredoc(t_data *data, int *bytes_readed, int *fd)
{
	char	*str;

	str = (data->input.buf + data->input.buf_idx);
	*bytes_readed = read(STDIN_FILENO, str, BUFSIZ - data->input.buf_idx);
	if (is_backspace(data) == YES)
		heredoc_delete_char(data);
	else if (is_ctrl(data, *bytes_readed) == YES)
		ft_bzero(str, BUFSIZ - data->input.buf_idx);
	else if (is_ctrl_c(data) == YES)
	{
		heredoc_ctrl_c(data, &fd);
		return (END);
	}
	else if (is_ctrl_d(data) == YES)
		heredoc_ctrl_d(data, &fd);
	else if (is_tab(data) == YES)
		execute_tab(data);
	else
		data->input.buf_idx += write(STDOUT_FILENO, str, *bytes_readed);
	return (CONTINUE);
}
