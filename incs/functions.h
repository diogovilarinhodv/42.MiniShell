/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:36:15 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 18:03:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	turn_on_canonical(t_data *data);
void	turn_off_canonical(t_data *data);

// 1.CHECKS_ENV
void	checks_env(char **env);

// 1.CHECKS_ENV > 1.is_valid
void	is_valid_env_var(char **env);
void	is_valid_stdin_fd(void);

// 2.INITIALIZE
void	initialize(t_data *data, int argc, char **argv, char **env);
void	initialize_env(t_data *data, char **env);
void	initialize_table(t_data *data);
void	initialize_input(t_data *data);
void	initialize_fd(t_data *data);
void	initialize_termcaps(t_data *data);
void	initialize_history(t_data *data);
void	initialize_signals(t_data *data);

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

// 3.READ_LINE
void	read_line(t_data *data);
void	read_char(t_data *data, int *bytes_readed);
void	turn_on_canonical(t_data *data);
void	turn_off_canonical(t_data *data);
void	write_prompt(t_data *data);
char	*get_input_str(t_data *data);
void	reset_line(t_data *data);
void	add_first_line_to_history(t_data *data);
void	add_other_line_to_history(t_data *data);
int		has_history(t_data *data);
void	select_history_cmd(t_data *data);
void	delete_char(t_data *data);
void	execute_up_arrow(t_data *data);
void	execute_down_arrow(t_data *data);
// 3.READ_LINE > 1.is
int		is_arrow(t_data *data);
int		is_ctrl(t_data *data, int bytes_readed);
int		is_ctrl_d(t_data *data);
int		is_ctrl_c(t_data *data);
int		is_backspace(t_data *data);
int		is_down_arrow(t_data *data);
int		is_up_arrow(t_data *data);

// 4.CHECKS_LINE
int		checks_input(t_data *data);
int		first_check(t_data *data);
void	remove_spaces_bysides(t_data *data);
int		second_check(t_data *data);

// 5.INPUT HANDLER
void	execute(t_data *data);
void	organize(t_data *data);

// 6.TOKEN_CREATION
void	get_tokens(t_data *data, int *pos_beg, int *pos_end);
void	get_token_pos_begin(t_data *data);
int		is_quote(t_data *data);
void	get_quote_pos_end(t_data *data);
void	get_token_pos_end(t_data *data);
int		exist_token(t_data *data, int pos_beg, int pos_end);
void	create_token(t_data *data, int pos_beg, int pos_end, char **token);

// 7.SET_TOKENS
int		is_cmd_delimiter(char *token);
int		is_table_delimiter(char *token);
int		is_first_table(t_data *data);
int		is_first_cmd(t_data *data);
int		is_redirection(char *token);

void	add_redirection_type(t_data *data, char *token);
void	add_redirection_token(t_data *data, char *token);
void	add_token(t_data *data, char *token);

void	add_first_redirection(t_data *data);
void	add_first_token(t_data *data, char *token);
void	add_first_cmd(t_data *data);
void	add_first_table(t_data *data);

void	add_another_redirection(t_data *data);
void	add_another_token(t_data *data, char *token);
void	add_another_cmd(t_data *data);
void	add_another_table(t_data *data);

void	add_delimiter(t_data *data, char *token);

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

// 9.REPLACE_TOKENS
int		token_has_cipher(t_data *data);
void	replace_env_var(t_data *data);
int		token_has_tilde(t_data *data);
void	replace_home_dir(t_data *data);
int		token_has_double_quotes(t_data *data);
int		token_has_single_quotes(t_data *data);
void	remove_double_quotes(t_data *data);
void	remove_single_quotes(t_data *data);

// 10.REPLACE_ENV_VARS
char	*create_tkn_replace(char *str_one, char *str_two, char *new_token);
char	*get_str_one_replace(t_data *data, int **inc_chr, int pos);
char	*get_str_two_replace(t_data *data, int **inc_chr);
char	*tkn_replace(t_data *data, int *inc_chr, int pos, char *new_tkn);
char	*append_tkn_replace(t_data *data, int str_one_pos, char *token);
char	*new_tkn_replace(t_data *data);

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

// 12.FILE_DESCRIPTORS
void	close_fd(t_data *data);
void	close_all_fd(t_data *data);
void	set_dup2(t_data *data);
int		is_only_one_cmd_fd(t_data *data);
int		is_first_cmd_fd(t_data *data);
int		is_middle_cmd_fd(t_data *data);
int		is_last_cmd_fd(t_data *data);

// 13.PATH_HANDLER
void	path_handler(t_data *data);
int		is_correct_path(char *path);
char	*get_path(t_data *data, char *str);
void	set_path(t_data *data, char *path);

// 14.ENV_HANDLER
char	*get_env_value(t_data *data, char *name);
int		get_env_idx(t_data *data, char *name);
void	set_env(t_data *data, char *name, char *value);
void	unset_env(t_data *data, char *name);

// 15.UTILS
int		count_chr(char *str, char c);
void	testing_stuffs(t_data *data);
void	end_program(t_data *data, int exit_status);
void	set_cur(t_data *data);
void	unset_cur(t_data *data);

// 16.LIBFT
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, char ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int qty);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isspace(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
int		ft_isascii(int c);
int		ft_putint(int c);
char	*ft_strcpy(char *dest, const char *src);
int		ft_putstr(char *str);

// 17.ERRORS
void	invalid_input(t_data *data);
void	env_empty(void);

// 18.FREE
void	free_env(t_data *data);
void	free_input(t_data *data);
void	free_store(t_data *data);
void	free_termcaps(t_data *data);
void	free_all_fd(t_data *data);
void	free_str(char **str);
void	free_str_bidimensional(char ***str);
void	free_str_bd_src(char ***str);

#endif
