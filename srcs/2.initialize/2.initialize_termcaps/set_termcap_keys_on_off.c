/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_keys_on_off.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:11:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 20:12:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_keys_on_off(t_data *data)
{
	data->termcaps.keys_on = tgetstr("ks", &data->termcaps.buffer);
	if (data->termcaps.keys_on)
		tputs(data->termcaps.keys_on, 1, ft_putint);
	data->termcaps.keys_off = tgetstr("ke", &data->termcaps.buffer);
}
