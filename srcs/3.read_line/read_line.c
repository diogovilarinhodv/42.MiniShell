/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:55:34 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:33:35 by dpestana         ###   ########.fr       */
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
		read_char(data, &bytes_readed);
	data->input.line = get_input_str(data);
	if (data->input.line == NULL)
		if (*data->input.line == '\0')
			return ;
	if (data->hist.str == NULL)
		add_first_line_to_history(data);
	else
		add_other_line_to_history(data);
}
