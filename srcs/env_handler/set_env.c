/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:00 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/27 18:47:19 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	sort_special_env_var(t_data *data)
{
	char	*name;
	char	*value;
	int		inc;

	inc = 0;
	name = NULL;
	value = NULL;
	while (inc < data->env.qty)
	{
		if (ft_strlen("_") == ft_strlen(*(data->env.name + inc)))
			if (ft_strncmp("_", *(data->env.name + inc), ft_strlen("_")) == 0)
				if (inc + 1 < data->env.qty)
				{
					name = *(data->env.name + inc);
					value = *(data->env.value + inc);
					*(data->env.name + inc) = *(data->env.name + inc + 1);
					*(data->env.value + inc) = *(data->env.value + inc + 1);
					*(data->env.name + inc + 1) = name;
					*(data->env.value + inc + 1) = value;
				}
		inc++;
	}
}

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
	if (data->env.name != NULL)
		free(data->env.name);
	if (data->env.value != NULL)
		free(data->env.value);
	data->env.name = tmp_name;
	data->env.value = tmp_value;
	sort_special_env_var(data);
}
