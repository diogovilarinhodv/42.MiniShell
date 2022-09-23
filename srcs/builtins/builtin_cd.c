/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 15:01:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_cd(t_data *data)
{
	char	*env_value;
	char	*pwd;

	if (data->tmp.cmd->qty == 2)
		chdir(*(data->tmp.cmd->token + 1));
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
