/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:03:28 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:37:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_arrow(t_data *data)
{
	char	*str;

	str = (data->input.buf + data->input.buf_idx);
	if (ft_strcmp(data->termcaps.up_arrow, str) == 0)
		return (YES);
	if (ft_strcmp(data->termcaps.down_arrow, str) == 0)
		return (YES);
	return (NO);
}
