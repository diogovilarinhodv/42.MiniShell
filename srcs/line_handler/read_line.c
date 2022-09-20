/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/22 16:33:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_line(t_data *data)
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
	freedom_input(data);
}
