/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_backspace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:10:17 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:19:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_backspace(t_data *data)
{
	if (IS_LINUX)
		data->termcaps.backspace = tgetstr("kb", &data->termcaps.buffer);
	else
		data->termcaps.backspace = ft_strdup("\x7f");
}
