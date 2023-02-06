/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.check_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:07:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_CHECK_LINE_H
# define D_CHECK_LINE_H

// 4.CHECKS_LINE
int		checks_input(t_data *data);
int		first_check(t_data *data);
int		second_check(t_data *data);

// 4.CHECKS_LINE > 1.remove
void	remove_spaces_bysides(t_data *data);
void	remove_right_spaces(t_data *data);
void	remove_left_spaces(t_data *data);

#endif