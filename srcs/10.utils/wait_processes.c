/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:11:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:10:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	wait_processes(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->cur.table->qty_cmd)
	{
		waitpid(*(data->tmp.pid + inc), NULL, 0);
		inc++;
	}
}