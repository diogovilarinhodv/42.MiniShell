/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:04:09 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/05 13:05:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	void	freedom_name_env(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		if ((data->env.name + inc) != NULL)
		{
			free(*(data->env.name + inc));
			*(data->env.name + inc) = NULL;
		}
		inc++;
	}
	if (data->env.name != NULL)
	{
		free(data->env.name);
		data->env.name = NULL;
	}
}

static	void	freedom_value_env(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		if ((data->env.value + inc) != NULL)
		{
			free(*(data->env.value + inc));
			*(data->env.value + inc) = NULL;
		}
		inc++;
	}
	if (data->env.value != NULL)
	{
		free(data->env.value);
		data->env.value = NULL;
	}
}

void	freedom_env(t_data *data)
{
	if (data->env.name != NULL)
		freedom_name_env(data);
	if (data->env.value != NULL)
		freedom_value_env(data);
	data->env.name = NULL;
	data->env.value = NULL;
	data->env.qty = 0;
}
