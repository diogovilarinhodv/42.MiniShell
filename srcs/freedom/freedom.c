/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:39 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:12:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom(t_data *data)
{
	freedom_input(data);
	//freedom_env(data);
	if (data->pwd != NULL)
		free(data->pwd);
	data->pwd = NULL;
}