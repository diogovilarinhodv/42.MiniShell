/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:05:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/12 23:46:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	is_number_builtin_exit(t_data *data)
{
	char	*str_error;
	char	*tmp;

	tmp = ft_strjoin("exit: ", *(data->cur.cmd->token + 1));
	str_error = ft_strjoin(tmp, ": numeric argument required\n");
	write_str(str_error);
	free_str(&tmp);
	free_str(&str_error);
	data->exit_status = EXIT_GENERAL_ERROR;
}

static int	is_long_long_int(t_data *data)
{
	int	len;

	len = ft_strlen(*(data->cur.cmd->token + 1));
	if (**(data->cur.cmd->token + 1) == '-')
	{
		if (len > 20)
			return (YES);
		else if (len == 20)
			if (ft_strcmp("-9223372036854775809", *(data->cur.cmd->token + 1)) <= 0)
				return (YES);
	}
	else
	{
		if (len > 19)
			return (YES);
		else if (len == 19)
			if (ft_strcmp("9223372036854775808", *(data->cur.cmd->token + 1)) <= 0)
				return (YES);
	}
	return (NO);
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
			data->exit_status = EXIT_FAILURE;
			return ;
		}
		else
		{
			if (is_long_long_int(data) == YES)
			{
				write_str("exit: ");
				write_str(*(data->cur.cmd->token + 1));
				write_str(": numeric argument required\n");
				data->exit_status = EXIT_GENERAL_ERROR;
			}
			else
				data->exit_status = ft_atoi(*(data->cur.cmd->token + 1));
		}
	}
	end_program(data, data->exit_status);
}
