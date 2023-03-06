/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_reset_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:25:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/06 16:14:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	heredoc_reset_line(t_data *data)
{
	write_str("^C\n");
	data->exit_status = EXIT_CMD_INTERRUPTED;
	ft_bzero(data->input.buf, BUFSIZ);
	data->input.buf_idx = 0;
}
