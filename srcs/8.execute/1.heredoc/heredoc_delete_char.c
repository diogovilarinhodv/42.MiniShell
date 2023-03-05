/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_delete_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:32:36 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 16:33:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	heredoc_delete_char(t_data *data)
{
	int		n;
	char	*str;

	if (data->input.buf_idx > 0)
		data->input.buf_idx--;
	str = (data->input.buf + data->input.buf_idx);
	ft_bzero(str, BUFSIZ - data->input.buf_idx);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	ft_putstr("> ");
	n = write_str(data->input.buf);
	data->input.buf_idx = n;
}
