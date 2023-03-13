/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctrl_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:28:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/12 23:53:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	heredoc_ctrl_d(t_data *data, int **fd)
{
	write_str("warning: here-document delimited by end-of-file (wanted \'");
	write_str(data->cur.cmd->red->token);
	write_str("\')\n");
	data->exit_status = EXIT_SUCCESS;
	set_exit_status_env(data);
	ft_bzero(data->input.buf, BUFSIZ);
	data->input.buf_idx = 0;
	turn_on_canonical(data);
	close(**fd);
	return (END);
}
