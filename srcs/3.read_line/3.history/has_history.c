/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:44:17 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:50:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	has_history(t_data *data)
{
	if (data->hist.qty_str == 0)
		return (NO);
	return (YES);
}
