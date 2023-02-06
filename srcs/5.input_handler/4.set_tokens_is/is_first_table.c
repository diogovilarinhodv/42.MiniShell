/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_first_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:19:05 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_first_table(t_data *data)
{
	if (data->store.qty_tbl == 0)
		return (YES);
	return (NO);
}
