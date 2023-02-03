/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:00:41 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/19 15:47:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	cd_back(t_data *data)
{
	char	*oldpwd;

	oldpwd = get_env_value(data, "OLDPWD");
	if (oldpwd == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	if (chdir(oldpwd) == -1)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	cd_update_pwd_oldpwd(data);
}
