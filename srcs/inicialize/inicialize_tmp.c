/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_tmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:32:26 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/03 10:33:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_tmp(t_data *data)
{
    data->tmp.cmd = NULL;
	data->tmp.idx = 0;
	data->tmp.pid = NULL;
	data->tmp.fd = malloc(sizeof(int) * 2);
}