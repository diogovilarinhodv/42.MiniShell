/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:04 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 22:55:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_ctrl(char c, int bytes_readed)
{
	if (bytes_readed != 1)
		return (NO);
	if (c == CTRL_C || c == CTRL_D || c == ENTER_KEY)
		return (NO);
	else if ((0 <= c && c <= 31) || c == 127)
		return (YES);
	return (NO);
}
