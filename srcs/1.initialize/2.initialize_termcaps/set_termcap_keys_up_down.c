/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_keys_up_down.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:13:00 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 20:13:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_keys_up_down(t_data *data)
{
	data->termcaps.up_arrow = tgetstr("ku", &data->termcaps.buffer);
	data->termcaps.down_arrow = tgetstr("kd", &data->termcaps.buffer);
}
