/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:24:17 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 15:47:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_ctrl_c(t_data *data)
{
	if (*(data->input.buf + data->input.buf_idx) == CTRL_C)
		return (YES);
	return (NO);
}
