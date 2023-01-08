/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:41:17 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/31 18:19:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	char	*set_name_builtin_export(t_data *data, int *inc)
{
	char	*env_name;

	while (*(*(data->cur.cmd->token + 1) + *inc) != '='
		&& *(*(data->cur.cmd->token + 1) + *inc) != '\0')
		(*inc)++;
	if (*(*(data->cur.cmd->token + 1) + *inc) == '\0')
		return (NULL);
	env_name = ft_substr(*(data->cur.cmd->token + 1), 0, *inc);
	return (env_name);
}

static	char	*set_value_builtin_export(t_data *data, int inc)
{
	char	*env_value;
	int		len;

	len = ft_strlen(*(data->cur.cmd->token + 1));
	if (*(*(data->cur.cmd->token + 1) + inc + 1) == '\"'
		 && *(*(data->cur.cmd->token + 1) + len - 1) == '\"')
		env_value = ft_substr(*(data->cur.cmd->token + 1),
				inc + 2,
				len - (inc + 3));
	else
		env_value = ft_substr(*(data->cur.cmd->token + 1),
				inc + 1,
				len - (inc + 1));
	return (env_value);
}

void	builtin_export(t_data *data)
{
	char	*env_name;
	char	*env_value;
	int		inc;

	inc = 0;
	env_name = set_name_builtin_export(data, &inc);
	if (env_name == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	env_value = set_value_builtin_export(data, inc);
	if (env_value == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	set_env(data, env_name, env_value);
	free_str(&env_name);
	free_str(&env_value);
	data->exit_status = EXIT_SUCCESS;
}
