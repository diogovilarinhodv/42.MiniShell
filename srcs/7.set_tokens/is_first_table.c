/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_first_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:19:05 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:04:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_first_table(t_data *data)
{
	if (data->store.qty_tbl == 0)
		return (YES);
	return (NO);
}
