/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.set_tokens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:11:41 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:12:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TOKENS_H
# define SET_TOKENS_H

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

#endif