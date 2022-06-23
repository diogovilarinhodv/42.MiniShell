/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:41:17 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/23 20:36:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_export(t_data *data)
{
	char	*env_name;
	char	*env_value;
	int		inc;

	env_name = NULL;
	env_value = NULL;
	inc = 0;
	while (*(*data->input.args + inc) != '=' && *(*data->input.args + inc) != '\0')
		inc++;
	if (*(*data->input.args + inc) == '\0')
		return ;
	env_name = ft_substr(*data->input.args, 0, inc);
	if (*(*data->input.args + inc + 1) == '\"' && *(*data->input.args + ft_strlen(*data->input.args) - 1) == '\"')
		env_value = ft_substr(*data->input.args, inc + 2, ft_strlen(*data->input.args) - (inc + 3));
	else
		env_value = ft_substr(*data->input.args, inc + 1, ft_strlen(*data->input.args) - (inc + 1));
	set_env(data, env_name, env_value);
	if (env_name != NULL)
		free(env_name);
	if (env_value != NULL)
		free(env_value);
}
