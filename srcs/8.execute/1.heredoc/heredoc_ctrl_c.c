/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctrl_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:31:22 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/12 23:48:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	heredoc_ctrl_c(t_data *data, int **fd)
{
	heredoc_reset_line(data);
	turn_on_canonical(data);
	close(**fd);
	delete_heredoc(data);
	data->cur.cmd->no_exec_heredoc = YES;
}
