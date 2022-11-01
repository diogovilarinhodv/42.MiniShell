/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:24:06 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:36:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	children_process(t_data *data)
{
	data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
	replace_tokens(data);
	if (builtins(data) == NO)
		non_builtin(data);
}