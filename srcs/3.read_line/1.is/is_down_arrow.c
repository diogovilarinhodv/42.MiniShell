/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_down_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:43:42 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:37:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_down_arrow(t_data *data)
{
	char	*str;

	str = (data->input.buf + data->input.buf_idx);
	if (ft_strcmp(data->termcaps.down_arrow, str) == 0)
		return (YES);
	return (NO);
}
