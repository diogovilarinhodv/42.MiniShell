/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap_old_term.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:56:43 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 13:46:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_termcap_old_term(t_data *data)
{
	if (tcgetattr(STDIN_FILENO, &data->termcaps.old_term) == -1)
		end_program(data, FAIL);
}
