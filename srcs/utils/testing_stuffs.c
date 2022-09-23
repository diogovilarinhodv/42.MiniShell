/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_stuffs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:04:23 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 10:04:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	testing_stuffs(t_data *data)
{
	if (data->line.qty_pipes > 0)
	{
		int inc;
		inc = 0;
		if (data->line.cmd != NULL)
		{
			if (data->line.cmd->token != NULL)
			{
				while (inc < data->line.qty_pipes + 1 && *(data->line.cmd + inc)->token != NULL)
				{
					printf("\n\n\n%s\n\n\n", *(data->line.cmd + inc)->token);
					inc++;
				}
			}
		}
	}
}