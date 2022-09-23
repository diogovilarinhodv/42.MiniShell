/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:38 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 09:13:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtins(t_data *data)
{
	int	len;
	int	qty_args;

	len = ft_strlen(*data->line.cmd->token);
	qty_args = data->line.cmd->qty;
	if (ft_strncmp(*data->line.cmd->token, "echo", len) == 0)
		builtin_echo(data);
	else if (ft_strncmp(*data->line.cmd->token, "cd", len) == 0)
		builtin_cd(data);
	else if (ft_strncmp(*data->line.cmd->token, "pwd", len) == 0 && qty_args == 0)
		builtin_pwd(data);
	else if (ft_strncmp(*data->line.cmd->token, "export", len) == 0 && qty_args == 1)
		builtin_export(data);
	else if (ft_strncmp(*data->line.cmd->token, "unset", len) == 0 && qty_args == 1)
		builtin_unset(data);
	else if (ft_strncmp(*data->line.cmd->token, "env", len) == 0 && qty_args == 0)
		builtin_env(data);
	else if (ft_strncmp(*data->line.cmd->token, "exit", len) == 0 && qty_args == 0)
		end_program(data);
	else
		return (NO);
	return (YES);
}
