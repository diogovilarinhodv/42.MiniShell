/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_has_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:45:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 17:40:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	echo_has_new_line(t_data *data, int *y)
{
	int	inc;

	inc = 1;
	if (data->cur.cmd->qty_tkn > 1)
	{
		if (**(data->cur.cmd->token + 1) == '-'
			&& *(*(data->cur.cmd->token + 1) + inc) == 'n')
		{
			while (*(*(data->cur.cmd->token + 1) + inc) == 'n')
				inc++;
			if (*(*(data->cur.cmd->token + 1) + inc) == '\0')
			{
				(*y)++;
				return (NO);
			}
		}
	}
	return (YES);
}
