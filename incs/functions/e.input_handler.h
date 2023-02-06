/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.input_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:32 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_INPUT_HANDLER_H
# define E_INPUT_HANDLER_H

// 5.INPUT HANDLER
void	running(t_data *data);
void	organize(t_data *data);

// 5.INPUT HANDLER > 1.token_creation
int		is_quote(t_data *data);
int		exist_token(t_data *data, int pos_beg, int pos_end);
void	create_token(t_data *data, int pos_beg, int pos_end, char **token);

// 5.INPUT HANDLER > 2.token_creation_get
void	get_tokens(t_data *data, int *pos_beg, int *pos_end);
void	get_token_pos_begin(t_data *data);
void	get_token_pos_end(t_data *data);
void	get_quote_pos_end(t_data *data);

// 5.INPUT HANDLER > 3.set_tokens
char	*non_cmd_limiter_run(t_data *data, char *token);
char	*cmd_limiter_run(t_data *data, char *token);

// 5.INPUT HANDLER > 4.set_tokens_is
int		is_table_delimiter(char *token);
int		is_first_table(t_data *data);
int		is_cmd_delimiter(char *token);
int		is_first_cmd(t_data *data);
int		is_redirection(char *token);

// 5.INPUT HANDLER > 5.set_tokens_add_table
void	add_first_table(t_data *data);
void	add_another_table(t_data *data);

// 5.INPUT HANDLER > 5.set_tokens_add_cmd
void	add_first_cmd(t_data *data);
void	add_another_cmd(t_data *data);

// 5.INPUT HANDLER > 5.set_tokens_add_token
void	add_token(t_data *data, char *token);
void	add_first_token(t_data *data, char *token);
void	add_another_token(t_data *data, char *token);

// 5.INPUT HANDLER > 5.set_tokens_add_redirections
void	add_first_redirection(t_data *data);
void	add_another_redirection(t_data *data);
void	add_redirection_type(t_data *data, char *token);
void	add_redirection_token(t_data *data, char *token);
void	add_delimiter(t_data *data, char *token);

#endif