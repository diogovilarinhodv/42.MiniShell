/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:15:22 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:15:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// 15.UTILS
int		count_chr(char *str, char c);
void	testing_stuffs(t_data *data);
void	end_program(t_data *data, int exit_status);
void	set_cur(t_data *data);
void	unset_cur(t_data *data);
void	turn_on_canonical(t_data *data);
void	turn_off_canonical(t_data *data);

#endif