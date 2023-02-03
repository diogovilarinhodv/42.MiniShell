/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:20:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 20:20:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_delete(t_data *data)
{
	data->termcaps.del_line = tgetstr("dl", &data->termcaps.buffer);
}
