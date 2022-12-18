/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_up_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:32:59 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 22:51:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_up_arrow(t_data *data)
{
	char	*input;

	if (data->hist.idx > -1)
		data->hist.idx--;
	if (data->hist.idx == -1)
	{
		data->hist.idx++;
		return ;
	}
	else if (data->hist.idx < data->hist.qty_str)
		input = *(data->hist.str + data->hist.idx);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	ft_bzero(data->input.buf, BUFSIZ);
	ft_strcpy(data->input.buf, input);
	data->input.buf_idx = write(STDOUT_FILENO, data->input.buf, ft_strlen(data->input.buf));
}
