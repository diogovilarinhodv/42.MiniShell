/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:20:38 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 22:23:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	get_env_idx(t_data *data, char *name)
{
	int		inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		if (ft_strlen(name) == ft_strlen(*(data->env.name + inc)))
			if (ft_strncmp(name, *(data->env.name + inc), ft_strlen(name)) == 0)
				return (inc);
		inc++;
	}
	return (-1);
}
