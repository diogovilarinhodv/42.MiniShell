/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 13:38:20 by dpestana         ###   ########.fr       */
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
		if (organize_input(data) == SUCCESS)
			execute_input(data);
	}
	//testing_stuffs(data);
	freedom(data, FREEDOM_INPUT);
	freedom(data, FREEDOM_LINE);
	inicialize_line(data);
}
