/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:10:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_env(t_data *data, char **env)
{
	int	inc;

	data->env.qty = 0;
	inc = 0;
	while (*(env + inc) != NULL)
		inc++;
	data->env.name = malloc(sizeof(char **) * inc);
	data->env.value = malloc(sizeof(char **) * inc);
	inc = 0;
	while (*(env + data->env.qty) != NULL)
	{
		inc = 0;
		while (*(*(env + data->env.qty) + inc) != '=')
			inc++;
		*(data->env.name + data->env.qty) = ft_substr(*(env + data->env.qty), 0, inc - 1);
		*(data->env.value + data->env.qty) = ft_substr(*(env + data->env.qty), inc + 1, ft_strlen(*(env + data->env.qty)) - (inc + 1));
		data->env.qty++;
	}
}
