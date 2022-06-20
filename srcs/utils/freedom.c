/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:39 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/19 18:09:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->input.line != NULL)
		free(data->input.line);
	if (data->input.cmd != NULL)
		free(data->input.cmd);
	if (data->input.args != NULL)
	{
		while (inc < data->input.qty_args)
		{
			if ((data->input.args + inc) != NULL)
				free((data->input.args + inc));
			inc++;
		}
		free(data->input.args);
	}
	if (data->pwd != NULL)
		free(data->pwd);
}