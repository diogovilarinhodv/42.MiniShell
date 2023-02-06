/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.env_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:14:55 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:15:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_ENV_HANDLER_H
# define N_ENV_HANDLER_H

// 14.ENV_HANDLER
char	*get_env_value(t_data *data, char *name);
int		get_env_idx(t_data *data, char *name);
void	set_env(t_data *data, char *name, char *value);
void	unset_env(t_data *data, char *name);

#endif