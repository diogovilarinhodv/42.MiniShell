/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:44:17 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 13:44:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	has_history(t_data *data)
{
	if (data->hist.qty_str == 0)
		return (NO);
	return (YES);
}
