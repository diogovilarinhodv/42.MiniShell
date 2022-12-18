/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:29:57 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 18:31:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_backspace(t_data *data)
{
	if (ft_strcmp((data->input.buf + data->input.buf_idx), data->termcaps.backspace) == 0)
		return (YES);
	return (NO);
}
