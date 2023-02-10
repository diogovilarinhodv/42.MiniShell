/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:44:12 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 16:01:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_tab(t_data *data)
{
	if (*(data->input.buf + data->input.buf_idx) == TAB_KEY)
		return (YES);
	return (NO);
}
