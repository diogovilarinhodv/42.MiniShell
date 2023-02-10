/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.check_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 15:57:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_CHECK_LINE_H
# define D_CHECK_LINE_H

// 4.CHECKS_LINE
int		checks_input(t_data *data);
int		checks_unexpected_token(t_data *data);
int		checks_invalid_token(t_data *data);
int		has_open_quotes(t_data *data);
int		has_char_at_begin(t_data *data, char c);
int		has_char_at_end(t_data *data, char c);

// 4.CHECKS_LINE > 1.is
int		is_line_empty(t_data *data);

// 4.CHECKS_LINE > 2.remove
void	remove_spaces_bysides(t_data *data);
void	remove_right_spaces(t_data *data);
void	remove_left_spaces(t_data *data);

// 4.CHECKS_LINE > 3.checks_unexpected_token
int		checks_chars(t_data *data);
int		checks_sequences(t_data *data);
int		has_char_at_begin(t_data *data, char c);
int		has_char_at_end(t_data *data, char c);
int		has_forbidden_sequence(t_data *data, char *seq);
int		has_open_quotes(t_data *data);
int		has_spaces(t_data *data);

// 4.CHECKS_LINE > 4.checks_unsupported_token
int		invalid_token(t_data *data, char *tkn);
int		invalid_and(t_data *data, char *seq);
int		space_between_char(t_data *data, char c);

#endif