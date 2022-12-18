/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:24:17 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 17:25:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_ctrl_c(t_data *data)
{
	if (*(data->input.buf + data->input.buf_idx) == CTRL_C)
		return (YES);
	return (NO);
}
