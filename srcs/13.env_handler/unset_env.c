/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:51 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/29 01:02:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	void	shorten_unset_env(t_data *data, int inc)
{
	if (*(data->env.name + inc) != NULL)
	{
		free(*(data->env.name + inc));
		*(data->env.name + inc) = NULL;
	}
	if (*(data->env.value + inc) != NULL)
	{
		free(*(data->env.value + inc));
		*(data->env.value + inc) = NULL;
	}
	while (inc + 1 < data->env.qty)
	{
		*(data->env.value + inc) = *(data->env.value + inc + 1);
		*(data->env.name + inc) = *(data->env.name + inc + 1);
		inc++;
	}
	data->env.qty--;
}

static	void	realloc_unset_env(t_data *data)
{
	int		inc;
	char	**tmp_name;
	char	**tmp_value;

	inc = 0;
	tmp_name = malloc(sizeof(char **) * data->env.qty);
	tmp_value = malloc(sizeof(char **) * data->env.qty);
	while (inc < data->env.qty)
	{
		*(tmp_name + inc) = *(data->env.name + inc);
		*(tmp_value + inc) = *(data->env.value + inc);
		inc++;
	}
	if (data->env.name != NULL)
	{
		free(data->env.name);
		data->env.name = NULL;
	}
	if (data->env.value != NULL)
	{
		free(data->env.value);
		data->env.value = NULL;
	}
	data->env.name = tmp_name;
	data->env.value = tmp_value;
}

void	unset_env(t_data *data, char *name)
{
	int	idx;

	idx = get_env_idx(data, name);
	if (idx == NOT_FOUND)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	shorten_unset_env(data, idx);
	realloc_unset_env(data);
	data->exit_status = EXIT_SUCCESS;
}
