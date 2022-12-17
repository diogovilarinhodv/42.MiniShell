/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arrow_pressed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:03:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/15 17:35:19 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_arrow_pressed(t_data *data, char *buf)
{
	if (ft_strcmp(data->termcaps.up_arrow, buf) == 0)
		return (YES);
	if (ft_strcmp(data->termcaps.down_arrow, buf) == 0)
		return (YES);
	return (NO);
}
