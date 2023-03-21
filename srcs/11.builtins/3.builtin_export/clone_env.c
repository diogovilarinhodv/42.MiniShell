/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 17:13:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

t_env_var	clone_env(t_data *data)
{
	t_env_var	env_sorted;
	int			inc;

	inc = 0;
	env_sorted.name = malloc(sizeof(char *) * data->env.qty);
	env_sorted.value = malloc(sizeof(char *) * data->env.qty);
	env_sorted.full = NULL;
	env_sorted.qty = data->env.qty;
	while (inc < data->env.qty)
	{
		*(env_sorted.name + inc) = ft_strdup(*(data->env.name + inc));
		*(env_sorted.value + inc) = ft_strdup(*(data->env.value + inc));
		inc++;
	}
	return (env_sorted);
}
