/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var_full.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:28:19 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/18 18:11:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_env_var_full(t_data *data)
{
	int		inc;
	char	*clone;

	inc = 0;
	data->env.full = malloc(sizeof(char *) * (data->env.qty + 1));
	while (inc < data->env.qty)
	{
		clone = ft_strjoin(*(data->env.name + inc), "=");
		*(data->env.full + inc) = ft_strjoin(clone, *(data->env.value + inc));
		free(clone);
		inc++;
	}
	*(data->env.full + inc) = NULL;
}
