/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:36:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/22 16:33:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// INICIALIZE
void	inicialize(t_data *data, int argc, char **argv, char **env);
void	inicialize_env(t_data *data, char **env);
void	inicialize_lst_cmd(t_data *data);

// UTILS
void	end_program(t_data *data);

// LINE HANDLER
void	read_line(t_data *data);
void	organize_line(t_data *data);
void	set_args(t_data *data, int pos_beg, int pos_end);
void	set_cmd(t_data *data, int *have_cmd, int pos_beg, int pos_end);
void	execute_line(t_data *data);

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
void	freedom_lst_cmd(t_data *data);

// ERRORS
void	invalid_line(t_data *data);
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

#endif
