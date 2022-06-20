/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:36:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/19 18:15:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// UTILS
void	inicialize(t_data *data, int argc, char **argv, char **env);
void	read_cmd(t_data *data);
void	organize_line(t_data *data);
void	freedom(t_data *data);


// BUILTINS
void	builtins(t_data *data);
void 	builtin_cd(t_data *data);
void	builtin_pwd(t_data *data);


// ERRORS
void	cmd_invalid(t_data *data);
void	env_empty(void);

// LIBFT
size_t	ft_strlen(const char *s);

#endif
