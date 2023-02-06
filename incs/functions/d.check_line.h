/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.check_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:22:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_CHECK_LINE_H
# define D_CHECK_LINE_H

// 4.CHECKS_LINE
int		checks_input(t_data *data);
int		first_check(t_data *data);
void	remove_spaces_bysides(t_data *data);
int		second_check(t_data *data);

#endif