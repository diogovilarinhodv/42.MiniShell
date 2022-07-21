/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:39 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 22:22:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

//freedom_env(data);

void	freedom(t_data *data)
{
	freedom_input(data);
	if (data->pwd != NULL)
		free(data->pwd);
	data->pwd = NULL;
}
