/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:40:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/13 15:49:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_path(t_data *data, char *new_path)
{
	if (new_path != NULL)
	{
		free(*data->cur.cmd->token);
		*data->cur.cmd->token = new_path;
	}
}
