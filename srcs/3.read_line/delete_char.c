/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:01:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 20:10:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	delete_char(t_data *data)
{
	if (data->input.buf_idx > 0)
		data->input.buf_idx--;
	ft_bzero((data->input.buf + data->input.buf_idx), BUFSIZ - data->input.buf_idx);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	data->input.buf_idx = write(STDOUT_FILENO, data->input.buf, ft_strlen(data->input.buf));
}
