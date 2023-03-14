/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.execute.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:12:06 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 13:52:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_EXECUTE_H
# define H_EXECUTE_H

// 8.EXECUTE
void	execute_table(t_data *data);
void	execute_cmd(t_data *data);
void	execute(t_data *data);
int		exit_table(t_data *data, int inc_tbl);
void	children_process(t_data *data);
void	replace_redirects(t_data *data);
void	replace_tokens(t_data *data);
void	set_redirects(t_data *data);
int		builtins(t_data *data);
void	non_builtin(t_data *data);
void	set_env_var_full(t_data *data);
void	unset_env_var_full(t_data *data);
void	save_std_fd(int *stdin_saved, int *stdout_saved);
void	close_std_fd(int *stdin_saved, int *stdout_saved);
void	set_exit_status_env(t_data *data);
void	set_last_cmd_env(t_data *data);
void	execve_error(t_data *data);
void	wait_child_pids(t_data *data);

// 8.EXECUTE > 1.heredoc
int		is_heredoc(t_data *data);
void	execute_heredoc(t_data *data);
int		read_char_heredoc(t_data *data, int *bytes_readed, int *fd);
void	delete_heredoc(t_data *data);
int		is_heredoc_terminator_str(t_data *data);
void	heredoc_write_on_file(t_data *data, int *fd, int *out);
void	heredoc_reset_line(t_data *data);
void	heredoc_ctrl_c(t_data *data, int **fd);
int		heredoc_ctrl_d(t_data *data, int **fd);
void	heredoc_delete_char(t_data *data);

// 8.EXECUTE > 2.file_open
int		file_open(char *filename, int type, int is_heredoc);
void	file_open_double_right_arrow(char *filename, int type, int *fd);
void	file_open_double_left_arrow(char *filename, int type, int *fd);
void	file_open_left_arrow(char *filename, int type, int *fd);
void	file_open_right_arrow(char *filename, int type, int *fd);

// 8.EXECUTE > 3.replace_tokens
char	*get_first_str_part(t_data *data);
int		is_cipher(t_data *data);
int		is_double_quote(t_data *data);
int		is_letter(t_data *data);
void	push_one_char(t_data *data, int idx);
void	replace_cipher(t_data *data);
void	replace_single_quotes(t_data *data);
void	replace_double_quotes(t_data *data);
void	replace_token(t_data *data);
void	replace_tokens_on_cmd(t_data *data);
int		is_single_quote(t_data *data);

#endif