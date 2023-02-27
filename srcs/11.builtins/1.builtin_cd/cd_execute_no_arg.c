/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute_no_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:59:13 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/27 12:33:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	cd_execute_no_arg(t_data *data)
{
	char	*env_value;

	env_value = get_env_value(data, "HOME");
	if (env_value == NULL)
	{
		write_str("Error\n");
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	if (chdir(env_value) == -1)
	{
		write_str("Error\n");
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	cd_update_pwd_oldpwd(data);
}
