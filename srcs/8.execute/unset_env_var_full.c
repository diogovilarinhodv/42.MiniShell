/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_var_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:58 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/18 18:11:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	unset_env_var_full(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->env.full != NULL)
	{
		free_env(data);
		set_env_lst(data, data->env.full);
		while (*(data->env.full + inc) != NULL)
		{
			free(*(data->env.full + inc));
			*(data->env.full + inc) = NULL;
			inc++;
		}
		free(*(data->env.full + inc));
		free(data->env.full);
		data->env.full = NULL;
	}
}
