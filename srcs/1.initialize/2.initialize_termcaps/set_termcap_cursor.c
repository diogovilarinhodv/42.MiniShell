/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_cursor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:21:07 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 20:21:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_cursor(t_data *data)
{
	data->termcaps.set_cursor_begin = tgetstr("cr", &data->termcaps.buffer);
}
