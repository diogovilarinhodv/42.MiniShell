/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_up_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:42:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 20:43:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_up_arrow(t_data *data)
{
	if (ft_strcmp(data->termcaps.up_arrow, (data->input.buf + data->input.buf_idx)) == 0)
		return (YES);
	return (NO);
}
