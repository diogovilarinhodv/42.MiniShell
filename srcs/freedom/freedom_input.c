/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:03:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:08:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom_input(t_data *data)
{
	int	inc;

	if (data->input.line != NULL)
		free(data->input.line);
	if (data->input.cmd != NULL)
		free(data->input.cmd);
	if (data->input.args != NULL)
	{
		inc = 0;
		while (inc < data->input.qty_args)
		{
			if ((data->input.args + inc) != NULL)
				free(*(data->input.args + inc));
			inc++;
		}
		free(data->input.args);
	}
	data->input.line = NULL;
	data->input.cmd = NULL;
	data->input.args = NULL;
	data->input.qty_args = 0;
}
