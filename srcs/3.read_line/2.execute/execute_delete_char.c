/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_delete_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:01:36 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:50:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	execute_delete_char(t_data *data)
{
	int		n;
	char	*str;

	if (data->input.buf_idx > 0)
		data->input.buf_idx--;
	str = (data->input.buf + data->input.buf_idx);
	ft_bzero(str, BUFSIZ - data->input.buf_idx);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	n = write(STDOUT_FILENO, data->input.buf, ft_strlen(data->input.buf));
	data->input.buf_idx = n;
}
