/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.initialize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:08:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:09:21 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

// 2.INITIALIZE
void	initialize(t_data *data, int argc, char **argv, char **env);
void	initialize_env(t_data *data, char **env);
void	initialize_table(t_data *data);
void	initialize_input(t_data *data);
void	initialize_fd(t_data *data);
void	initialize_termcaps(t_data *data);
void	initialize_history(t_data *data);
void	initialize_signals(void);

// 2.INITIALIZE > 1.initialize_env
void	set_env_lst_alloc_name(t_data *data);
void	set_env_lst_alloc_value(t_data *data);
char	*set_env_lst_get_name(t_data *data, char *env_var);
char	*set_env_lst_get_value_idx(t_data *data, char *env_var);
char	*set_env_lst_get_value(t_data *data, char *env_var);
void	set_env_lst_set_qty(t_data *data, char **env);
void	set_env_lst(t_data *data, char **env);

void	shlvl_env_default_config(t_data *data);
void	shlvl_env_increase(t_data *data, char *str_shlvl_value);

// 2.INITIALIZE > 2.initialize_termcaps
void	set_termcap_backspace(t_data *data);
void	set_termcap_buffer(t_data *data);
void	set_termcap_cursor(t_data *data);
void	set_termcap_delete(t_data *data);
void	set_termcap_keys_on_off(t_data *data);
void	set_termcap_keys_up_down(t_data *data);
void	set_termcap_old_term(t_data *data);
int		set_termcap_config(t_data *data);
void	valid_termcap_config(t_data *data);

// 2.INITIALIZE > 3.initialize_signals
void	catch_sigint(int signum);
void	catch_sigquit(int signum);

#endif