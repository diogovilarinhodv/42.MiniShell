/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:12:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 20:00:05 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_env(t_data *data, char **env)
{
	int	env_qty;

	data->env.qty = 0;
	while (*(env + data->env.qty) != NULL)
		data->env.qty++;
	env_qty = data->env.qty;
	data->env.name = malloc(sizeof(char **) * data->env.qty);
	data->env.value = malloc(sizeof(char **) * data->env.qty);
	while (data->env.qty > 0)
		set_env_lst(data, env);
	data->env.qty = env_qty;
	data->env.full = NULL;
	unset_env(data, "OLDPWD");
	set_shlvl_env(data);
}
