/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_off_canonical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:58:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/15 16:58:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	turn_off_canonical(t_data *data)
{
	data->termcaps.new_term = data->termcaps.old_term;
	data->termcaps.new_term.c_lflag &= ~ICANON;
	data->termcaps.new_term.c_lflag &= ~ECHO;
	data->termcaps.new_term.c_lflag &= ~ISIG;
	data->termcaps.new_term.c_lflag &= ~IEXTEN;
	data->termcaps.new_term.c_iflag &= ~IXON;
	data->termcaps.new_term.c_cc[VMIN] = 1;
	data->termcaps.new_term.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->termcaps.new_term) == -1)
		end_program(data, FAIL);
}
