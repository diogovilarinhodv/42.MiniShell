/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_write_on_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:22 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 14:57:04 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	heredoc_write_on_file(t_data *data, int *fd, int *out)
{
	if (*fd != -1)
		dup2(*fd, STDOUT_FILENO);
	write(*fd, data->input.buf, ft_strlen(data->input.buf));
	dup2(*out, STDOUT_FILENO);
	free_input(data);
}
