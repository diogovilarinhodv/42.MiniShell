/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.read_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:09:45 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:19:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

// 3.READ_LINE
void	read_line(t_data *data);
void	read_char(t_data *data, int *bytes_readed);
void	turn_on_canonical(t_data *data);
void	turn_off_canonical(t_data *data);
void	write_prompt(t_data *data);
char	*get_input_str(t_data *data);
void	reset_line(t_data *data);
void	add_first_line_to_history(t_data *data);
void	add_other_line_to_history(t_data *data);
int		has_history(t_data *data);
void	select_history_cmd(t_data *data);
void	delete_char(t_data *data);
void	execute_up_arrow(t_data *data);
void	execute_down_arrow(t_data *data);
// 3.READ_LINE > 1.is
int		is_arrow(t_data *data);
int		is_ctrl(t_data *data, int bytes_readed);
int		is_ctrl_d(t_data *data);
int		is_ctrl_c(t_data *data);
int		is_backspace(t_data *data);
int		is_down_arrow(t_data *data);
int		is_up_arrow(t_data *data);

#endif