/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.file_descriptors.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:14:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:14:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DESCRIPTORS_H
# define FILE_DESCRIPTORS_H

// 12.FILE_DESCRIPTORS
void	close_fd(t_data *data);
void	close_all_fd(t_data *data);
void	set_dup2(t_data *data);
int		is_only_one_cmd_fd(t_data *data);
int		is_first_cmd_fd(t_data *data);
int		is_middle_cmd_fd(t_data *data);
int		is_last_cmd_fd(t_data *data);

#endif