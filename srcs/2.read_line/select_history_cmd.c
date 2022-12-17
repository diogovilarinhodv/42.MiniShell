/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_history_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:38:16 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/17 04:07:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	select_history_cmd(t_data *data, char *buf, int *i)
{
	char	*input;

	if (has_history(data) == NO)
	{
		ft_bzero(&buf[*i], BUFSIZ - *i);
		return ;
	}
	if (ft_strcmp(data->termcaps.up_arrow, &buf[*i]) == 0)
	{
		data->hist.idx++;
		if (data->hist.idx == data->hist.qty_str)
			data->hist.idx--;
		input = *(data->hist.str + data->hist.idx);
	}
	else if (ft_strcmp(data->termcaps.down_arrow, &buf[*i]) == 0)
	{
		data->hist.idx--;
		if (data->hist.idx == -1)
			data->hist.idx++;
		input = *(data->hist.str + data->hist.idx);
	}
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	ft_bzero(buf, BUFSIZ);
	ft_strcpy(buf, input);
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
}