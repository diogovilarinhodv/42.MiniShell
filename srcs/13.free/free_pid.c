/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:21:27 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:22:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_pid(t_data *data)
{
    if (data->tmp.pid != NULL)
	{
		free(data->tmp.pid);
		data->tmp.pid = NULL;
	}
}