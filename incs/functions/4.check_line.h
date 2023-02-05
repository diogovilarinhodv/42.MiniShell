/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.check_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:10:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_LINE_H
# define CHECKS_LINE_H

// 4.CHECKS_LINE
int		checks_input(t_data *data);
int		first_check(t_data *data);
void	remove_spaces_bysides(t_data *data);
int		second_check(t_data *data);

#endif