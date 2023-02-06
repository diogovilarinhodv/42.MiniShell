/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:13:36 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:15:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef K_BUILTINS_H
# define K_BUILTINS_H

// 11.BUILTINS
void	builtin_cd(t_data *data);
void	builtin_env(t_data *data);
void	builtin_pwd(t_data *data);
void	builtin_echo(t_data *data);
void	builtin_exit(t_data *data);
void	builtin_unset(t_data *data);
void	builtin_export(t_data *data);
void	builtin_history(t_data *data);

// 11.BUILTINS > 1.BUILTIN_CD
void	cd_execute_no_arg(t_data *data);
void	cd_execute_one_arg(t_data *data);
void	cd_arg(t_data *data);
void	cd_back(t_data *data);
void	cd_update_pwd_oldpwd(t_data *data);

// 11.BUILTINS > 2.BUILTIN_ECHO
int		echo_has_new_line(t_data *data, int *y);

// 11.BUILTINS > 3.BUILTIN_EXPORT
char	*export_set_name(t_data *data, int *inc);
char	*export_set_value(t_data *data, int inc);

#endif