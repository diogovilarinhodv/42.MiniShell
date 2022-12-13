/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:10:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:12:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	close_all_fd(t_data *data)
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
