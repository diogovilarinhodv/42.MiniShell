/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:55:34 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/17 04:10:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_line(t_data *data)
{
	int		bytes_readed;
	char	buf[BUFSIZ];
	int		i;

	i = 0;
	ft_bzero(buf, BUFSIZ);
	turn_off_canonical(data);
	write_prompt(data);
	data->hist.idx = 0;
	while (ft_strchr(buf, '\n') == NULL)
	{
		bytes_readed = read(STDIN_FILENO, &buf[i], BUFSIZ - i);
		if (is_arrow_pressed(data, &buf[i]))
			select_history_cmd(data, buf, &i);
		else if (ft_strcmp(&buf[i], data->termcaps.backspace) == 0)
			delete_char(data, buf, &i);
		else if (bytes_readed > 2 || is_ctrl(buf[i], bytes_readed))
			ft_bzero(&buf[i], BUFSIZ - i);
		else if (buf[i] == CTRL_C)
			reset_line(data, buf, &i);
		else if (buf[i] == CTRL_D)
			end_program(data, SUCCESS);
		else
			i += write(STDOUT_FILENO, &buf[i], bytes_readed);
	}
	data->input.line = get_input_str(data, buf, i);
	add_line_to_history(data);
	add_history(data->input.line);
}