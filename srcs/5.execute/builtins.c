/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:38 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/12 19:18:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtins(t_data *data)
{
	int	len;

	len = ft_strlen(*data->tmp.cmd->token);
	if (ft_strncmp(*data->tmp.cmd->token, "echo", len) == 0 && len == (int)ft_strlen("echo"))
		builtin_echo(data);
	else if (ft_strncmp(*data->tmp.cmd->token, "cd", len) == 0 && len == (int)ft_strlen("cd"))
		builtin_cd(data);
	else if (ft_strncmp(*data->tmp.cmd->token, "pwd", len) == 0 && len == (int)ft_strlen("pwd") && data->tmp.cmd->qty_tkn == 1)
		builtin_pwd(data);
	else if (ft_strncmp(*data->tmp.cmd->token, "export", len) == 0 && len == (int)ft_strlen("export") && data->tmp.cmd->qty_tkn == 2)
		builtin_export(data);
	else if (ft_strncmp(*data->tmp.cmd->token, "unset", len) == 0 && len == (int)ft_strlen("unset") && data->tmp.cmd->qty_tkn == 2)
		builtin_unset(data);
	else if (ft_strncmp(*data->tmp.cmd->token, "env", len) == 0 && len == (int)ft_strlen("env") && data->tmp.cmd->qty_tkn == 1)
		builtin_env(data);
	else if (ft_strncmp(*data->tmp.cmd->token, "exit", len) == 0 && len == (int)ft_strlen("exit") && data->tmp.cmd->qty_tkn == 1)
		end_program(data, SUCCESS);
	else
		return (NO);
	return (YES);
}
