/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_update_pwd_oldpwd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:01:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/28 16:07:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	cd_update_pwd_oldpwd(t_data *data)
{
	char	*new_pwd;
	char	*pwd;

	new_pwd = getcwd(NULL, 0);
	if (new_pwd == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	pwd = get_env_value(data, "PWD");
	if (pwd == NULL)
	{
		free(new_pwd);
		new_pwd = NULL;
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	set_env(data, "OLDPWD", pwd);
	set_env(data, "PWD", new_pwd);
	free(new_pwd);
	new_pwd = NULL;
	data->exit_status = EXIT_SUCCESS;
}
