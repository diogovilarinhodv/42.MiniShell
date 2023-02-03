/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_has_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:45:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/19 16:46:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	echo_has_new_line(t_data *data, int *y)
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
