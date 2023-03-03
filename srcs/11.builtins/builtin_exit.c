/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:05:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/03 14:46:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	is_number_builtin_exit(t_data *data)
{
	char	*str_error;
	char	*tmp;

	str_error = NULL;
	tmp = NULL;
	tmp = ft_strjoin("exit: ", *(data->cur.cmd->token + 1));
	str_error = ft_strjoin(tmp, ": numeric argument required\n");
	write_str(str_error);
	free_str(&tmp);
	free_str(&str_error);
}

void	builtin_exit(t_data *data)
{
	write_str("exit\n");
	if (data->cur.cmd->qty_tkn > 1)
	{
		if (is_number(*(data->cur.cmd->token + 1)) == NO)
			is_number_builtin_exit(data);
		else if (data->cur.cmd->qty_tkn > 2)
		{
			write_str("exit: too many arguments\n");
			return ;
		}
	}
	data->exit_status = ft_atoi(*(data->cur.cmd->token + 1));
	while (data->exit_status < 256)
		data->exit_status /= 255;
	end_program(data, data->exit_status);
}
