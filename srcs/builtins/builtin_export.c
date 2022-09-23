/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:41:17 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 14:53:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

/*
	[set_name_builtin_export]

		Find '=' or '\0', getting name final pos

		Checks for '\0', Verify if it ends without a value

		Set the name to env_name var.
*/

static	char	*set_name_builtin_export(t_data *data, int *inc)
{
	char	*env_name;

	while (*(*data->tmp.cmd->token + *inc) != '=' && *(*data->tmp.cmd->token + *inc) != '\0')
		(*inc)++;
	if (*(*data->tmp.cmd->token + *inc) == '\0')
		return (NULL);
	env_name = ft_substr(*data->tmp.cmd->token, 0, *inc);
	return (env_name);
}

/*
	[set_value_builtin_export]

		Checks if value has quotes, if has, set value without they.
		if hasnt, just set the value.
*/

static	char	*set_value_builtin_export(t_data *data, int inc)
{
	char	*env_value;
	int		len;

	len = ft_strlen(*data->tmp.cmd->token);
	if (*(*data->tmp.cmd->token + inc + 1) == '\"'
		 && *(*data->tmp.cmd->token + len - 1) == '\"')
		env_value = ft_substr(*data->tmp.cmd->token, inc + 2, len - (inc + 3));
	else
		env_value = ft_substr(*data->tmp.cmd->token, inc + 1, len - (inc + 1));
	return (env_value);
}

/*
	[freedom_builtin_export]

		Free env_name.
		Set env_name to NULL.
		Free env_value.
		Set env_value to NULL.
*/

static	void	freedom_builtin_export(char *env_name, char *env_value)
{
	if (env_name != NULL)
	{
		free(env_name);
		env_name = NULL;
	}
	if (env_value != NULL)
	{
		free(env_value);
		env_value = NULL;
	}
}

/*
	[builtin_export]

		Set var(name & value) to the env var list.
*/

void	builtin_export(t_data *data)
{
	char	*env_name;
	char	*env_value;
	int		inc;

	inc = 0;
	env_name = set_name_builtin_export(data, &inc);
	if (env_name == NULL)
		return ;
	env_value = set_value_builtin_export(data, inc);
	if (env_value == NULL)
		return ;
	set_env(data, env_name, env_value);
	freedom_builtin_export(env_name, env_value);
}
