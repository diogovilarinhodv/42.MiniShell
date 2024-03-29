/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:48:56 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:04:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_echo(t_data *data)
{
	int		has_newline;
	int		y;
	char	*str;

	y = 1;
	has_newline = echo_has_new_line(data, &y);
	while (y < data->cur.cmd->qty_tkn)
	{
		str = *(data->cur.cmd->token + y);
		write_str(str);
		if (y + 1 < data->cur.cmd->qty_tkn)
			write_str(" ");
		y++;
	}
	if (has_newline == YES)
		write_str("\n");
	data->exit_status = EXIT_SUCCESS;
}
