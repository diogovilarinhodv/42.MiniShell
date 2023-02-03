/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute_no_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:59:13 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/19 15:47:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	cd_execute_no_arg(t_data *data)
{
	char	*env_value;

	env_value = get_env_value(data, "HOME");
	if (env_value == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	if (chdir(env_value) == -1)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	cd_update_pwd_oldpwd(data);
}
