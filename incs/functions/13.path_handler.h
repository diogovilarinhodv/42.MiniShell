/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.path_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:14:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:14:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_HANDLER_H
# define PATH_HANDLER_H

// 13.PATH_HANDLER
void	path_handler(t_data *data);
int		is_correct_path(char *path);
char	*get_path(t_data *data, char *str);
void	set_path(t_data *data, char *path);

#endif