/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:48:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/07 22:57:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	has_newline_func(t_data *data, int *y)
{
	if (data->cur.cmd->qty_tkn > 1)
	{
		if (ft_strcmp(*(data->cur.cmd->token + 1), "-n") == 0)
		{
			(*y)++;
			return (NO);
		}
	}
	return (YES);
}

void	builtin_echo(t_data *data)
{
	int		has_newline;
	int		y;

	y = 1;
	has_newline = has_newline_func(data, &y);
	while (y < data->cur.cmd->qty_tkn)
	{
		printf("%s", *(data->cur.cmd->token + y));
		if (y + 1 < data->cur.cmd->qty_tkn)
			printf(" ");
		y++;
	}
	if (has_newline == YES)
		printf("\n");
}
