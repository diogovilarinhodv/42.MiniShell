/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:41:17 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 17:18:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_export(t_data *data)
{
	if (data->cur.cmd->qty_tkn == 1)
		builtin_export_no_args(data);
	else
		builtin_export_with_arg(data);
}
