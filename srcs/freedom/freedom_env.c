/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:04:09 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 22:21:14 by dpestana         ###   ########.fr       */
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
			free(*(data->env.name + inc));
		inc++;
	}
	free(data->env.name);
}

static	void	freedom_value_env(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		if ((data->env.value + inc) != NULL)
			free(*(data->env.value + inc));
		inc++;
	}
	free(data->env.value);
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
