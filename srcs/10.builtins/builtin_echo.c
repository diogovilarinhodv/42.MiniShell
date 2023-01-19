/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:48:56 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/19 16:45:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_echo(t_data *data)
{
	int		has_newline;
	int		y;

	y = 1;
	has_newline = echo_has_new_line(data, &y);
	while (y < data->cur.cmd->qty_tkn)
	{
		write(STDOUT_FILENO, *(data->cur.cmd->token + y), ft_strlen(*(data->cur.cmd->token + y)));
		if (y + 1 < data->cur.cmd->qty_tkn)
			write(STDOUT_FILENO, " ", 1);
		y++;
	}
	if (has_newline == YES)
		write(STDOUT_FILENO, "\n", ft_strlen("\n"));
	data->exit_status = EXIT_SUCCESS;
}
