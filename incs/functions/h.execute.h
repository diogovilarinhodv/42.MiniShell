/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.execute.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:12:06 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 17:36:10 by dpestana         ###   ########.fr       */
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

#endif