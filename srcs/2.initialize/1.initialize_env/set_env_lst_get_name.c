/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst_get_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:46:12 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:27:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*set_env_lst_get_name(t_data *data, char *env_var)
{
	char	*idx_value_str;
	int		env_var_len;
	int		idx_value_str_len;
	char	*name;

	idx_value_str = set_env_lst_get_value_idx(data, env_var);
	idx_value_str = (idx_value_str - 1);
	idx_value_str_len = ft_strlen(idx_value_str);
	if (idx_value_str_len == 0)
		end_program(data, FAIL);
	env_var_len = ft_strlen(env_var);
	if (env_var_len == 0)
		end_program(data, FAIL);
	name = ft_substr(env_var, 0, env_var_len - idx_value_str_len);
	if (name == NULL)
		end_program(data, FAIL);
	return (name);
}
