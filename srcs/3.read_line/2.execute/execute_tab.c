/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:55:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 16:01:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	execute_tab(t_data *data)
{
	int		n;
	char	*str;

	data->input.buf_idx += 4;
	str = (data->input.buf + data->input.buf_idx);
	ft_bzero(str, BUFSIZ - data->input.buf_idx);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	n = write(STDOUT_FILENO, data->input.buf, ft_strlen(data->input.buf));
	data->input.buf_idx = n;
}
