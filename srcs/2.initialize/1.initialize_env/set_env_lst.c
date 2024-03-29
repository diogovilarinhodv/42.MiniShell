/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:10:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_env_lst(t_data *data, char **env)
{
	int		inc;

	inc = 0;
	set_env_lst_set_qty(data, env);
	set_env_lst_alloc_name(data);
	set_env_lst_alloc_value(data);
	while (inc < data->env.qty)
	{
		*(data->env.name + inc) = set_env_lst_get_name(data, *(env + inc));
		*(data->env.value + inc) = set_env_lst_get_value(data, *(env + inc));
		inc++;
	}
}
