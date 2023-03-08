/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:41:17 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/08 15:11:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_export(t_data *data)
{
	char	*env_name;
	char	*env_value;
	int		inc;

	inc = 0;
	env_name = export_set_name(data, &inc);
	if (env_name == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	env_value = export_set_value(data, inc);
	if (env_value == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	set_env(data, env_name, env_value);
	free_str(&env_name);
	free_str(&env_value);
	data->exit_status = EXIT_SUCCESS;
}
