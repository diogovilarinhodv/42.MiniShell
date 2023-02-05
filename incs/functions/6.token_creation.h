/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.token_creation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:11:01 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:11:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_CREATION_H
# define TOKEN_CREATION_H

// 6.TOKEN_CREATION
void	get_tokens(t_data *data, int *pos_beg, int *pos_end);
void	get_token_pos_begin(t_data *data);
int		is_quote(t_data *data);
void	get_quote_pos_end(t_data *data);
void	get_token_pos_end(t_data *data);
int		exist_token(t_data *data, int pos_beg, int pos_end);
void	create_token(t_data *data, int pos_beg, int pos_end, char **token);

#endif