/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:04:09 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:09:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom_env(t_data *data)
{
	int	inc;
	
	if (data->env.name != NULL)
	{
		inc = 0;
		while (inc < data->env.qty)
		{
			if ((data->env.name + inc) != NULL)
				free(*(data->env.name + inc));
			inc++;
		}
		free(data->env.name);
	}
	if (data->env.value != NULL)
	{
		inc = 0;
		while (inc < data->env.qty)
		{
			if ((data->env.value + inc) != NULL)
				free(*(data->env.value + inc));
			inc++;
		}
		free(data->env.value);
	}
	data->env.name = NULL;
	data->env.value = NULL;
	data->env.qty = 0;
}
