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
	data->line = readline(BCYN "➜  " BGRN "MiniShell:" RST);
	if (data->line == NULL)
		invalid_line(data);
	if (*data->line)
	{
		add_history(data->line);
		organize_line(data);
		execute_line(data);
	}
	// if for testing, delete after testing
	if (data->qty_pipes > 0)
	{
		int inc;
		inc = 0;
		while (inc < data->qty_pipes + 1)
		{
			printf("\n\n\n%s\n\n\n", (data->lst_cmd + inc)->cmd);
			inc++;
		}
	}
	freedom(data, FREEDOM_LST_CMD);
	freedom(data, FREEDOM_LINE);
}
