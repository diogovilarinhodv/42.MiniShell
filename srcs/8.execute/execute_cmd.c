/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/04 17:16:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	is_heredoc(t_data *data)
{
	if (data->cur.cmd->is_heredoc == YES)
		return (YES);
	return (NO);
}

static void	read_char_heredoc(t_data *data, int *bytes_readed)
{
	char	*str;

	str = (data->input.buf + data->input.buf_idx);
	*bytes_readed = read(STDIN_FILENO, str, BUFSIZ - data->input.buf_idx);
	if (is_arrow(data))
		select_history_cmd(data);
	else if (is_backspace(data) == YES)
		execute_delete_char(data);
	else if (is_ctrl(data, *bytes_readed) == YES)
		ft_bzero(str, BUFSIZ - data->input.buf_idx);
	else if (is_ctrl_c(data) == YES)
		reset_line(data);
	else if (is_ctrl_d(data) == YES)
	{
		if (data->input.buf_idx < 1)
			end_program(data, SUCCESS);
	}
	else if (is_tab(data) == YES)
		execute_tab(data);
	else
		data->input.buf_idx += write(STDOUT_FILENO, str, *bytes_readed);
}

static void	execute_heredoc(t_data *data)
{
	int		bytes_readed;
	int		fd;
	int		out;

	free_input(data);
	fd = open("tmp_file", O_WRONLY | O_CREAT | O_APPEND, 0666);
	out = dup(STDOUT_FILENO);
	while (1)
	{
		ft_putstr("> ");
		turn_off_canonical(data);
		initialize_input(data);
		while (ft_strchr(data->input.buf, '\n') == NULL)
			read_char_heredoc(data, &bytes_readed);
		turn_on_canonical(data);
		*(data->input.buf + data->input.buf_idx - 1) = '\0';
		if (ft_strcmp(data->input.buf, data->cur.cmd->red->token) == 0)
			break ;
		*(data->input.buf + data->input.buf_idx - 1) = '\n';
		*(data->input.buf + data->input.buf_idx) = '\0';
		if (fd != -1)
			dup2(fd, STDOUT_FILENO);
		write(fd, data->input.buf, ft_strlen(data->input.buf));
		dup2(out, STDOUT_FILENO);
		free_input(data);
	}
	close(fd);
}

static void	delete_heredoc(t_data *data)
{
	data->cur.cmd->is_heredoc = NO;
}

void	execute_cmd(t_data *data)
{
	int		stdin_saved;
	int		stdout_saved;

	data->cur.idx_cmd = 0;
	while (data->cur.idx_cmd < data->cur.table->qty_cmd)
	{
		data->cur.cmd = (data->cur.table->cmd + data->cur.idx_cmd);
		save_std_fd(&stdin_saved, &stdout_saved);
		replace_tokens(data);
		replace_redirects(data);
		data->cur.cmd->is_heredoc = 1;
		if (is_heredoc(data) == YES)
			execute_heredoc(data);
		set_redirects(data);
		execute(data);
		if (is_heredoc(data) == YES)
			delete_heredoc(data);
		unset_env_var_full(data);
		close_std_fd(&stdin_saved, &stdout_saved);
		set_last_cmd_env(data);
		set_exit_status_env(data);
		data->cur.idx_cmd++;
	}
}
