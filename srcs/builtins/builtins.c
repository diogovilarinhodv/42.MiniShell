/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/22 14:41:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void builtins(t_data *data)
{
	int	len;

	len = ft_strlen(data->input.cmd);
	if (ft_strncmp(data->input.cmd, "pwd", len) == 0 && data->input.qty_args == 0)
		builtin_pwd(data);
	if (ft_strncmp(data->input.cmd, "cd", len) == 0)
		builtin_cd(data);
	//if (data->input.qty_args == 0)
	//	env_var(data);
	if (ft_strncmp(data->input.cmd, "env", len) == 0 && data->input.qty_args == 0)
		builtin_env(data);
	if (ft_strncmp(data->input.cmd, "unset", len) == 0 && data->input.qty_args == 1)
		builtin_unset(data);
	if (ft_strncmp(data->input.cmd, "exit", len) == 0 && data->input.qty_args == 0)
		end_program(data);
}