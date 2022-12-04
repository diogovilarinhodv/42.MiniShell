/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:36:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/04 20:46:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// 1.INICIALIZE
void	inicialize(t_data *data, int argc, char **argv, char **env);
void	inicialize_env(t_data *data, char **env);
void	inicialize_table(t_data *data);
void	inicialize_input(t_data *data);
void	inicialize_fd(t_data *data);

// 2.CHECKS_INPUT
int     checks_input(t_data *data);
int		first_check(t_data *data);
void    remove_spaces_bysides(t_data *data);
int		second_check(t_data *data);

// 3.INPUT HANDLER
void	execute(t_data *data);
void	organize(t_data *data);

// 4.TOKEN_CREATION
void	get_tokens(t_data *data, int *pos_beg, int *pos_end);
void	get_token_pos_begin(t_data *data);
int     is_quote(t_data *data);
void    get_quote_pos_end(t_data *data);
void	get_token_pos_end(t_data *data);
int		exist_token(t_data *data, int pos_beg, int pos_end);
void	create_token(t_data *data, int pos_beg, int pos_end, char **token);


// 5.SET_TOKENS
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


// 6.REPLACE_TOKENS
int     token_has_cipher(t_data *data, int inc);
void	replace_env_var(t_data *data, int inc);
int     token_has_tilde(t_data *data, int inc);
void	replace_home_dir(t_data *data, int inc);
int     token_has_quotes(t_data *data, int inc);
void	remove_quotes(t_data *data, int inc);

// 7.EXECUTES
void	execute_table(t_data *data);
void	execute_cmd(t_data *data);
void	children_process(t_data *data);
void	replace_tokens(t_data *data);
int		builtins(t_data *data);
void	non_builtin(t_data *data);

// 8.FILE_DESCRIPTORS
void	close_fd(t_data *data);
void	close_all_fd(t_data *data);
void	set_dup2(t_data *data);
int		is_only_one_cmd_fd(t_data *data);
int		is_first_cmd_fd(t_data *data);
int		is_middle_cmd_fd(t_data *data);
int		is_last_cmd_fd(t_data *data);


// 8.PATH_HANDLER
void	path_handler(t_data *data);
int		is_correct_path(char *path);
char	*get_path(t_data *data, char *str);
void	set_path(t_data *data, char *path);

// 8.BUILTINS
void	builtin_cd(t_data *data);
void	builtin_pwd(t_data *data);
void	builtin_env(t_data *data);
void	builtin_echo(t_data *data);
void	builtin_unset(t_data *data);
void	builtin_export(t_data *data);

// 9.ENV_HANDLER
char	*get_env_value(t_data *data, char *name);
int		get_env_idx(t_data *data, char *name);
void	set_env(t_data *data, char *name, char *value);
void	unset_env(t_data *data, char *name);

// 10.UTILS
int		count_chr(char *str, char c);
void	testing_stuffs(t_data *data);
void	end_program(t_data *data, int status);
void	set_cur(t_data *data);
void	unset_cur(t_data *data);

// 11.LIBFT
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, char ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int qty);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isspace(int c);

// 12.ERRORS
void	invalid_input(t_data *data);
void	env_empty(void);

// 13.FREE
void	free_env(t_data *data);
void	free_input(t_data *data);
void	free_store(t_data *data);
void	free_fd(t_data *data);
void	free_str(char **str);
void	free_str_bidimensional(char ***str);

#endif
