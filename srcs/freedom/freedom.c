/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:39 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/22 11:47:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom(t_data *data, int status)
{
	if (status == FREEDOM_INPUT || status == FREEDOM_ALL)
		freedom_input(data);
	if (status == FREEDOM_ENV || status == FREEDOM_ALL)
		freedom_env(data);
	if (status == FREEDOM_CMD || status == FREEDOM_ALL)
		freedom_cmd(data);
	if (status == FREEDOM_LINE || status == FREEDOM_ALL)
		freedom_line(data);
}
