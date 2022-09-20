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
	freedom(data, FREEDOM_LST_CMD);
	freedom(data, FREEDOM_LINE);
}
