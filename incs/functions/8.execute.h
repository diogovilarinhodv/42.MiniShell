/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.execute.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:12:06 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:12:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

// 8.EXECUTE
void	execute_table(t_data *data);
void	execute_cmd(t_data *data);
void	children_process(t_data *data);
void	replace_tokens(t_data *data);
void	set_redirects(t_data *data);
int		builtins(t_data *data);
void	non_builtin(t_data *data);
void	set_env_var_full(t_data *data);
void	unset_env_var_full(t_data *data);

#endif