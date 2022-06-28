/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:51 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/22 15:29:35 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	unset_env(t_data *data, char *name)
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
				free(*(data->env.name + inc));
				free(*(data->env.value + inc));
				while (inc + 1 < data->env.qty)
				{
					*(data->env.value + inc) = *(data->env.value + inc + 1);
					*(data->env.name + inc) = *(data->env.name + inc + 1);
					inc++;
				}
				data->env.qty--;
				tmp_name = malloc(sizeof(char **) * data->env.qty);
				tmp_value = malloc(sizeof(char **) * data->env.qty);
				inc = 0;
				while (inc < data->env.qty)
				{
					*(tmp_name + inc) = *(data->env.name + inc);
					*(tmp_value + inc) = *(data->env.value + inc);
					inc++;
				}
				free(data->env.name);
				free(data->env.value);
				data->env.name = tmp_name;
				data->env.value = tmp_value;
				break;
			}
		inc++;
	}
}
