/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:38 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 09:47:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtins(t_data *data)
{
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
	else if (ft_strcmp(*data->cur.cmd->token, "exit") == 0)
		end_program(data, SUCCESS);
	else
		return (NO);
	return (YES);
}
