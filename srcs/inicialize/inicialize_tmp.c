/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_tmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:32:26 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/04 12:04:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_tmp(t_data *data)
{
	data->tmp.cmd = NULL;
	data->tmp.idx = 0;
	data->tmp.pid = NULL;
	data->tmp.fd = malloc(sizeof(int) * 2);
	pipe(data->tmp.fd);
}