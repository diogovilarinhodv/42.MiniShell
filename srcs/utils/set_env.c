/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:00 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/23 20:39:04 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_env(t_data *data, char *name, char *value)
{
	int		inc;
	char	**tmp_name;
	char	**tmp_value;

	inc = 0;
	tmp_name = NULL;
	tmp_value = NULL;
	while (inc < data->env.qty)
	{
		if (ft_strlen(name) == ft_strlen(*(data->env.name + inc)))
			if (ft_strncmp(name, *(data->env.name + inc), ft_strlen(name)) == 0)
			{
				free(*(data->env.value + inc));
				*(data->env.value + inc) = ft_strdup(value);
				return ;
			}
		inc++;
	}
	data->env.qty++;
	tmp_name = malloc(sizeof(char **) * data->env.qty);
	tmp_value = malloc(sizeof(char **) * data->env.qty);
	inc = 0;
	while (inc < data->env.qty - 1)
	{
		*(tmp_name + inc) = *(data->env.name + inc);
		*(tmp_value + inc) = *(data->env.value + inc);
		inc++;
	}
	*(tmp_name + inc) = ft_strdup(name);
	*(tmp_value + inc) = ft_strdup(value);
	free(data->env.name);
	free(data->env.value);
	data->env.name = tmp_name;
	data->env.value = tmp_value;
}
