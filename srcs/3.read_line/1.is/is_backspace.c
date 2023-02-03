/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:29:57 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:37:47 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_backspace(t_data *data)
{
	char	*str;

	str = (data->input.buf + data->input.buf_idx);
	if (ft_strcmp(str, data->termcaps.backspace) == 0)
		return (YES);
	return (NO);
}
