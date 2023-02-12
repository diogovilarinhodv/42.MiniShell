/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:05:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 17:34:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_exit(t_data *data)
{
	char	*str_error;
	char	*tmp;

	str_error = NULL;
	tmp = NULL;
	write_str("exit\n");
	if (data->cur.cmd->qty_tkn > 1)
	{
		if (is_number(*(data->cur.cmd->token + 1)) == NO)
		{
			tmp = ft_strjoin("exit: ", *(data->cur.cmd->token + 1));
			str_error = ft_strjoin(tmp, ": numeric argument required\n");
			write_str(str_error);
			free_str(&tmp);
			free_str(&str_error);
		}
		else if (data->cur.cmd->qty_tkn > 2)
			write_str("exit: too many arguments\n");
	}
	end_program(data, SUCCESS);
}
