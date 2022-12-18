/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 13:51:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_cd(t_data *data)
{
	char	*env_value;
	char	*new_pwd;
	char	*pwd;

	if (data->cur.cmd->qty_tkn == 2)
		chdir(*(data->cur.cmd->token + 1));
	else
	{
		env_value = get_env_value(data, "HOME");
		if (env_value != NULL)
			chdir(env_value);
	}
	new_pwd = getcwd(NULL, 0);
	if (new_pwd != NULL)
	{
		pwd = get_env_value(data, "PWD");
		if (pwd != NULL)
			set_env(data, "OLDPWD", pwd);
		set_env(data, "PWD", new_pwd);
		free(new_pwd);
		new_pwd = NULL;
	}
}
