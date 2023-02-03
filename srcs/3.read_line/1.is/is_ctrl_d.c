/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ctrl_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:25:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:23:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_ctrl_d(t_data *data)
{
	if (*(data->input.buf + data->input.buf_idx) == CTRL_D)
		return (YES);
	return (NO);
}
