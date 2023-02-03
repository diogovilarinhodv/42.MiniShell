/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_termcaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:49:37 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 22:53:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_termcaps(t_data *data)
{
	set_termcap_old_term(data);
	set_termcap_buffer(data);
	set_termcap_keys_on_off(data);
	set_termcap_keys_up_down(data);
	set_termcap_backspace(data);
	set_termcap_delete(data);
	set_termcap_cursor(data);
	valid_termcap_config(data);
}
