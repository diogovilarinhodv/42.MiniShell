/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.free.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:16:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/07 08:34:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_FREE_H
# define R_FREE_H

// 18.FREE
void	free_env(t_data *data);
void	free_input(t_data *data);
void	free_store(t_data *data);
void	free_termcaps(t_data *data);
void	free_table_fd(t_data *data, int inc_tbl);
void	free_table_all_fd(t_data *data);
void	free_str(char **str);
void	free_str_bidimensional(char ***str);
void	free_str_bd_src(char ***str);

#endif
