/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/13 15:44:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	path_handler(t_data *data)
{
	char	*path_env;
	char	*new_path;

	path_env = NULL;
	new_path = NULL;
	if (**data->cur.cmd->token == '/' || **data->cur.cmd->token == '.')
		return ;
	path_env = get_env_value(data, "PATH");
	if (path_env != NULL)
	{
		new_path = get_path(data, path_env);
		set_path(data, new_path);
	}
}
