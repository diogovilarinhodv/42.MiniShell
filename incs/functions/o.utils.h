/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:15:22 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:14:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_UTILS_H
# define O_UTILS_H

// 15.UTILS
int		count_chr(char *str, char c);
void	testing_stuffs(t_data *data);
void	end_program(t_data *data, int exit_status);
void	set_cur(t_data *data);
void	unset_cur(t_data *data);
void	turn_on_canonical(t_data *data);
void	turn_off_canonical(t_data *data);

#endif