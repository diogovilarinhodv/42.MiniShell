/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:36:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:07:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// UTILS
void	inicialize(t_data *data, int argc, char **argv, char **env);
void	inicialize_env(t_data *data, char **env);
void	read_cmd(t_data *data);
void	organize_line(t_data *data);



// BUILTINS
void	builtins(t_data *data);
void 	builtin_cd(t_data *data);
void	builtin_pwd(t_data *data);
void	env_var(t_data *data);

// FREE
void	freedom(t_data *data);
void	freedom_env(t_data *data);
void	freedom_input(t_data *data);

// ERRORS
void	input_invalid(t_data *data);
void	env_empty(void);

// LIBFT
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
