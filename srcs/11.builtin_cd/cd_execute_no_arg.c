/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute_no_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:59:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/28 16:07:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

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
