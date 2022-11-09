/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:10:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 12:04:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	close_fd(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->cur.table->qty_cmd)
	{
		close(data->store.table->fd[inc][0]);
		close(data->store.table->fd[inc][1]);
		inc++;
	}
}