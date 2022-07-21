/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:39:16 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 18:28:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_line(t_data *data)
{
	data->input.line = NULL;
	data->input.cmd = NULL;
	data->input.args = NULL;
	data->input.qty_args = 0;
	data->pwd = NULL;
}
