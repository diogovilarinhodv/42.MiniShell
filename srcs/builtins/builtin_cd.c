/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 22:27:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_cd(t_data *data)
{
	char	*env_value;

	if (data->input.qty_args == 1)
		chdir(*data->input.args);
	else
	{
		env_value = get_env_value(data, "HOME");
		if (env_value != NULL)
			chdir(env_value);
	}
	if (data->pwd != NULL)
		free(data->pwd);
	data->pwd = getcwd(NULL, 0);
}
