/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 16:44:06 by dpestana         ###   ########.fr       */
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
