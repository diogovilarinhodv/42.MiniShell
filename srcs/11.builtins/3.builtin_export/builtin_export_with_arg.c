/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_with_arg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:17:49 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 12:03:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	builtin_export_with_arg(t_data *data)
{
	char	*env_name;
	char	*env_value;
	int		inc;

	inc = 0;
	env_name = export_set_name(data, &inc);
	if (env_name == NULL)
		return ;
	env_value = export_set_value(data, inc);
	set_env(data, env_name, env_value);
	free_str(&env_name);
	free_str(&env_value);
	data->exit_status = EXIT_SUCCESS;
}
