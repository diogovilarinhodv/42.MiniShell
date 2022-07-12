/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:07:05 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/18 16:58:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_cmd(t_data *data)
{
	data->input.line = readline(BCYN "➜  " BGRN "MiniShell:" RST);
	if (data->input.line == NULL)
		invalid_line(data);
	if (*data->input.line)
	{
		add_history(data->input.line);
		organize_line(data);
		execute_line(data);
	}
	freedom(data);
}