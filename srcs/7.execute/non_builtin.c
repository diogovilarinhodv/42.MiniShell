/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/06 11:47:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
// ping -c 5 google.com | grep rtt
// cat filer | grep bla | wc

void	non_builtin(t_data *data)
{
	int	pid;

	//*(data->cur.table->pid + data->cur.idx_cmd) = fork();
	//if (*(data->cur.table->pid + data->cur.idx_cmd) == 0)
	pid = fork();
	if (pid == 0)
		children_process(data);
	if (data->cur.table->qty_cmd > 1)
		set_dup2(data);
}
