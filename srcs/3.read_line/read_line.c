/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:55:34 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:30:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_line(t_data *data)
{
	int		bytes_readed;

	turn_off_canonical(data);
	write_prompt(data);
	set_history_idx(data);
	initialize_input(data);
	while (ft_strchr(data->input.buf, '\n') == NULL)
		read_char(data, &bytes_readed);
	if (set_input_line(data) == FAIL)
		return ;
	add_line_to_history(data);
}
