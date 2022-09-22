/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:38 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 22:27:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtins(t_data *data)
{
	int	len;
	int	qty_args;

	len = ft_strlen(data->line.basic_cmdcmd);
	qty_args = data->line.cmd->qty;
	if (ft_strncmp(data->line.basic_cmdcmd, "echo", len) == 0)
		builtin_echo(data);
	else if (ft_strncmp(data->line.basic_cmdcmd, "cd", len) == 0)
		builtin_cd(data);
	else if (ft_strncmp(data->line.basic_cmdcmd, "pwd", len) == 0 && qty_args == 0)
		builtin_pwd(data);
	else if (ft_strncmp(data->line.basic_cmdcmd, "export", len) == 0 && qty_args == 1)
		builtin_export(data);
	else if (ft_strncmp(data->line.basic_cmdcmd, "unset", len) == 0 && qty_args == 1)
		builtin_unset(data);
	else if (ft_strncmp(data->line.basic_cmdcmd, "env", len) == 0 && qty_args == 0)
		builtin_env(data);
	else if (ft_strncmp(data->line.basic_cmdcmd, "exit", len) == 0 && qty_args == 0)
		end_program(data);
	else
		return (NO);
	return (YES);
}
