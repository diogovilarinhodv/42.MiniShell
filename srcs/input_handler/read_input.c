/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/05 17:18:21 by dpestana         ###   ########.fr       */
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
	testing_stuffs(data);
	freedom(data, FREEDOM_INPUT);
	freedom(data, FREEDOM_LINE);
	freedom_tmp(data);
	inicialize_line(data);
	inicialize_tmp(data);
}
