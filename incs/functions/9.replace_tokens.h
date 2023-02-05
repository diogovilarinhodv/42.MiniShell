/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.replace_tokens.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:12:34 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:12:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_TOKENS_H
# define REPLACE_TOKENS_H

// 9.REPLACE_TOKENS
int		token_has_cipher(t_data *data);
void	replace_env_var(t_data *data);
int		token_has_tilde(t_data *data);
void	replace_home_dir(t_data *data);
int		token_has_double_quotes(t_data *data);
int		token_has_single_quotes(t_data *data);
void	remove_double_quotes(t_data *data);
void	remove_single_quotes(t_data *data);

#endif