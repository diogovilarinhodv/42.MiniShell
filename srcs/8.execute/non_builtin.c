/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/23 14:06:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	non_builtin(t_data *data)
{
	data->cur.cmd->pid = fork();
	if (data->cur.cmd->pid == 0)
		children_process(data);
}
