/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:00 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 16:00:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	sort_special_env_var(t_data *data)
{
	char	*name;
	char	*value;
	int		idx;

	name = NULL;
	value = NULL;
	idx = get_env_idx(data, "_");
	if (idx != NOT_FOUND)
	{
		if (idx + 1 < data->env.qty)
		{
			name = *(data->env.name + idx);
			value = *(data->env.value + idx);
			*(data->env.name + idx) = *(data->env.name + idx + 1);
			*(data->env.value + idx) = *(data->env.value + idx + 1);
			*(data->env.name + idx + 1) = name;
			*(data->env.value + idx + 1) = value;
		}
	}
}

static	void	realloc_set_env(t_data *data, char *name, char *value)
{
	int		inc;
	char	**tmp_name;
	char	**tmp_value;

	inc = 0;
	tmp_name = malloc(sizeof(char **) * data->env.qty);
	tmp_value = malloc(sizeof(char **) * data->env.qty);
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
}

void	set_env(t_data *data, char *name, char *value)
{
	int		idx;

	idx = get_env_idx(data, name);
	if (idx != NOT_FOUND)
	{
		free(*(data->env.value + idx));
		*(data->env.value + idx) = ft_strdup(value);
		return ;
	}
	data->env.qty++;
	realloc_set_env(data, name, value);
	sort_special_env_var(data);
}
