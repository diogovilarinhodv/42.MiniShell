/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:11:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:20:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	process_wait(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->cur.table->qty_cmd)
	{
		waitpid(*(data->tmp.pid + inc), NULL, 0);
		inc++;
	}
}