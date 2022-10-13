/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:11:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/12 18:12:04 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	wait_processes(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->line.qty_cmd)
	{
		waitpid(*(data->tmp.pid + inc), NULL, 0);
		inc++;
	}
}