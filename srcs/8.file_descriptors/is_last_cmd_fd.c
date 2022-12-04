/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:28:21 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/04 20:46:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_last_cmd_fd(t_data *data)
{
	if (data->cur.idx_cmd == (data->store.table->qty_cmd - 1))
		return (YES);
	return (NO);
}
