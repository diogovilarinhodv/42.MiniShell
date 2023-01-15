/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:38 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/15 10:06:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtins(t_data *data)
{
	set_dup2(data);
	if (ft_strcmp(*data->cur.cmd->token, "echo") == 0)
		builtin_echo(data);
	else if (ft_strcmp(*data->cur.cmd->token, "cd") == 0)
		builtin_cd(data);
	else if (ft_strcmp(*data->cur.cmd->token, "pwd") == 0)
		builtin_pwd(data);
	else if (ft_strcmp(*data->cur.cmd->token, "export") == 0)
		builtin_export(data);
	else if (ft_strcmp(*data->cur.cmd->token, "unset") == 0)
		builtin_unset(data);
	else if (ft_strcmp(*data->cur.cmd->token, "env") == 0)
		builtin_env(data);
	else if (ft_strcmp(*data->cur.cmd->token, "history") == 0)
		builtin_history(data);
	else if (ft_strcmp(*data->cur.cmd->token, "exit") == 0)
		builtin_exit(data);
	else
		return (NO);
	return (YES);
}
