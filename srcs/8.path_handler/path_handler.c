/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/02 22:36:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	path_handler(t_data *data)
{
	char	*path_env;
	char	*path;

	if (**data->cur.cmd->token == '/' || **data->cur.cmd->token == '.')
		return ;
	path_env = get_env_value(data, "PATH");
	path = get_path(data, path_env);
	set_path(data, path);
}
