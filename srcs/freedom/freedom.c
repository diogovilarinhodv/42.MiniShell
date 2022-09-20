/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:39 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/22 13:20:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom(t_data *data, int status)
{
	if (status == FREEDOM_LINE || status == FREEDOM_ALL)
	{
		if (data->line != NULL)
			free(data->line);
		data->line = NULL;
	}
	if (status == FREEDOM_LST_CMD || status == FREEDOM_ALL)
		freedom_lst_cmd(data);
	if (status == FREEDOM_ENV || status == FREEDOM_ALL)
		freedom_env(data);
}
