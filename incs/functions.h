/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:36:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 11:13:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// INICIALIZE
void	inicialize(t_data *data, int argc, char **argv, char **env);
void	inicialize_env(t_data *data, char **env);
void	inicialize_line(t_data *data);
void	inicialize_input(t_data *data);

// UTILS
void	add_cmd(t_data *data);
void	testing_stuffs(t_data *data);
void	end_program(t_data *data);

// INPUT HANDLER
void	read_input(t_data *data);
void	organize_input(t_data *data);
void	execute_input(t_data *data);
void	set_cmd(t_data *data, int has_pipe, int pos_beg, int pos_end);


// BUILTINS
int		builtins(t_data *data);
void	builtin_cd(t_data *data);
void	builtin_pwd(t_data *data);
void	builtin_env(t_data *data);
void	builtin_echo(t_data *data);
void	builtin_unset(t_data *data);
void	builtin_export(t_data *data);
void	env_var(t_data *data);
void	non_builtin(t_data *data);

// FREE
void	freedom(t_data *data, int status);
void	freedom_env(t_data *data);
void	freedom_input(t_data *data);
void	freedom_line(t_data *data);

// ERRORS
void	invalid_input(t_data *data);
void	env_empty(void);

// ENV VAR HANDLER
char	*get_env_value(t_data *data, char *name);
int		get_env_idx(t_data *data, char *name);
void	set_env(t_data *data, char *name, char *value);
void	unset_env(t_data *data, char *name);

// LIBFT
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isspace(int c);

#endif
