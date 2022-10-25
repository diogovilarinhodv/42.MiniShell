/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:23:14 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 16:11:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_first_cmd(t_data *data)
{
	if (data->store.qty_tbl == 0)
		return (YES);
	if ((data->store.table + data->store.qty_tbl - 1)->qty_cmd == 0)
		return (YES);
	return (NO);
}