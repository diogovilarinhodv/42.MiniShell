/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_on_canonical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:58:41 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:20:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	turn_on_canonical(t_data *data)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->termcaps.old_term) == -1)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
}
