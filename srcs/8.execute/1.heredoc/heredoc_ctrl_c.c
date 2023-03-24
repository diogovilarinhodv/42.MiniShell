/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctrl_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:31:22 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 14:20:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	heredoc_ctrl_c(t_data *data, int **fd)
{
	heredoc_reset_line(data);
	turn_on_canonical(data);
	close(**fd);
	close(data->out_hd);
	delete_heredoc(data);
	data->cur.cmd->exec_hd = YES;
}
