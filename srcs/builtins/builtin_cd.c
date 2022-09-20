/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/22 13:19:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_cd(t_data *data)
{
	char	*env_value;
	char	*pwd;

	if (data->lst_cmd->qty_args == 1)
		chdir(*data->lst_cmd->args);
	else
	{
		env_value = get_env_value(data, "HOME");
		if (env_value != NULL)
			chdir(env_value);
	}
	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		set_env(data, "PWD", pwd);
		free(pwd);
	}
}
