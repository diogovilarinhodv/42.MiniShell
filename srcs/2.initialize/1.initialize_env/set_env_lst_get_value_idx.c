/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst_get_value_idx.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:04:59 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:05:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*set_env_lst_get_value_idx(t_data *data, char *env_var)
{
	char	*idx_value_str;

	idx_value_str = ft_strchr(env_var, '=');
	if (idx_value_str == NULL)
		end_program(data, FAIL);
	return (idx_value_str + 1);
}
