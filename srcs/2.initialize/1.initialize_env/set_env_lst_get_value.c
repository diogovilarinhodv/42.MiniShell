/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst_get_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:05:25 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:10:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*set_env_lst_get_value(t_data *data, char *env_var)
{
	char	*idx_value_str;
	char	*value;

	idx_value_str = set_env_lst_get_value_idx(data, env_var);
	value = ft_strdup(idx_value_str);
	if (value == NULL)
		end_program(data, FAIL);
	return (value);
}
