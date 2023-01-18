/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_one_cmd_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:27:02 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/18 22:37:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_only_one_cmd_fd(t_data *data)
{
	if (data->cur.table->qty_cmd == 1)
		return (YES);
	return (NO);
}
