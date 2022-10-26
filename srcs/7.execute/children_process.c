/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:24:06 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:11:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	children_process(t_data *data)
{
	if (*(data->tmp.pid + data->cur.idx_cmd) == 0)
	{
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		replace_tokens(data);
		if (builtins(data) == NO)
			non_builtin(data);
		data->cur.cmd = NULL;
	}
}