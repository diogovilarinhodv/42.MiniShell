/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/13 12:41:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	path_handler(t_data *data)
{
	char	*path_env;
	char	*path;

	path = NULL;
	path_env = NULL;
	if (**data->cur.cmd->token == '/' || **data->cur.cmd->token == '.')
		return ;
	path_env = get_env_value(data, "PATH");
	if (path_env != NULL)
		path = get_path(data, path_env);
	set_path(data, path);
}
