/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:47:38 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/02 21:51:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_path(t_data *data, char *path)
{
	if (path != NULL)
	{
		free(*data->cur.cmd->token);
		*data->cur.cmd->token = path;
	}
}
