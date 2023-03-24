/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:25:30 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 14:13:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	execute_heredoc(t_data *data)
{
	int		bytes_readed;
	int		fd;
	int		out;

	free_input(data);
	fd = open("tmp_file", O_WRONLY | O_CREAT | O_APPEND, 0666);
	data->out_hd = dup(STDOUT_FILENO);
	while (1)
	{
		ft_putstr("> ");
		initialize_input(data);
		turn_off_canonical(data);
		while (ft_strchr(data->input.buf, '\n') == NULL)
			if (read_char_heredoc(data, &bytes_readed, &fd) == END)
				return ;
		turn_on_canonical(data);
		if (is_heredoc_terminator_str(data) == YES)
			break ;
		heredoc_write_on_file(data, &fd);
	}
	free_input(data);
	close(fd);
}
