/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.read_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:09:45 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 15:57:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_READ_LINE_H
# define C_READ_LINE_H

// 3.READ_LINE
void	read_line(t_data *data);
void	read_char(t_data *data, int *bytes_readed);
void	write_prompt(t_data *data);
void	reset_line(t_data *data);

// 3.READ_LINE > 1.is
int		is_arrow(t_data *data);
int		is_ctrl(t_data *data, int bytes_readed);
int		is_ctrl_d(t_data *data);
int		is_ctrl_c(t_data *data);
int		is_backspace(t_data *data);
int		is_down_arrow(t_data *data);
int		is_up_arrow(t_data *data);
int		is_tab(t_data *data);

// 3.READ_LINE > 2.execute
void	execute_delete_char(t_data *data);
void	execute_up_arrow(t_data *data);
void	execute_down_arrow(t_data *data);
void	execute_tab(t_data *data);

// 3.READ_LINE > 3.history
void	add_line_to_history(t_data *data);
void	add_first_line_to_history(t_data *data);
void	add_other_line_to_history(t_data *data);
int		has_history(t_data *data);
void	select_history_cmd(t_data *data);
void	set_history_idx(t_data *data);

// 3.READ_LINE > 4.input
char	*get_input_str(t_data *data);
int		set_input_line(t_data *data);

#endif