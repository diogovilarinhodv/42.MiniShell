/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:30:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void builtin_cd(t_data *data)
{
	int		success;
	char	*env_value;

	if (data->input.qty_args == 1)
		success = chdir(*data->input.args);
	else
	{
		env_value = get_env_value(data, "HOME");
		if (env_value != NULL)
			success = chdir(env_value);
		else
			success = -1;
	}
	if (success < 0)
		printf("error!\n");
	if (data->pwd != NULL)
		free(data->pwd);
	data->pwd = getcwd(NULL, 0);
}