/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.replace_env_vars.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:13:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:15:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_REPLACE_ENV_VARS_H
# define J_REPLACE_ENV_VARS_H

// 10.REPLACE_ENV_VARS
char	*create_tkn_replace(char *str_one, char *str_two, char *new_token);
char	*get_str_one_replace(t_data *data, int **inc_chr, int pos);
char	*get_str_two_replace(t_data *data, int **inc_chr);
char	*tkn_replace(t_data *data, int *inc_chr, int pos, char *new_tkn);
char	*append_tkn_replace(t_data *data, int str_one_pos, char *token);
char	*new_tkn_replace(t_data *data);

#endif