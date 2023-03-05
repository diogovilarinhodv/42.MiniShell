/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctrl_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:28:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 16:29:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	heredoc_ctrl_d(t_data *data, int **fd)
{
	if (data->input.buf_idx < 1)
	{
		turn_on_canonical(data);
		close(**fd);
		delete_heredoc(data);
		end_program(data, SUCCESS);
	}
}
