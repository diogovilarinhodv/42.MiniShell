/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 15:54:21 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_ctrl(t_data *data, int bytes_readed)
{
	char	ch;

	ch = *(data->input.buf + data->input.buf_idx);
	if (bytes_readed > 2)
		return (YES);
	else if (bytes_readed != 1)
		return (NO);
	else if (ch == CTRL_C || ch == CTRL_D || ch == ENTER_KEY || ch == TAB_KEY)
		return (NO);
	else if ((0 <= ch && ch <= 31) || ch == 127)
		return (YES);
	return (NO);
}
