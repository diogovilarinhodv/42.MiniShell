/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/22 12:10:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	read_input(t_data *data)
{
	data->input = readline(BCYN "➜  " BGRN "MiniShell:" RST);
	if (data->input == NULL)
		invalid_input(data);
	if (*data->input)
	{
		add_history(data->input);
		organize_input(data);
		execute_input(data);
	}
	// if for testing, delete after testing
	if (data->line.qty_pipes > 0)
	{
		int inc;
		inc = 0;
		while (inc < data->line.qty_pipes + 1)
		{
			printf("\n\n\n%s\n\n\n", (data->line.cmd + inc)->token);
			inc++;
		}
	}
	freedom(data, FREEDOM_INPUT);
	freedom(data, FREEDOM_CMD);
	freedom(data, FREEDOM_LINE);
}
