/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/27 12:39:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_cd(t_data *data)
{
	if (data->cur.cmd->qty_tkn == 1)
		cd_execute_no_arg(data);
	else if (data->cur.cmd->qty_tkn == 2)
		cd_execute_one_arg(data);
	else
	{
		data->exit_status = EXIT_FAILURE;
		write_str("cd: too many arguments\n");
	}
}
