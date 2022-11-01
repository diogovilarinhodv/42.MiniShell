/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:10:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:11:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	close_fd(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->cur.table->qty_cmd)
	{
		close(data->tmp.fd[inc][0]);
		close(data->tmp.fd[inc][1]);
		inc++;
	}
}