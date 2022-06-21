/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:24:48 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:26:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_env_value(t_data *data, char *name)
{
	int	inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		if (ft_strlen(name) == ft_strlen(*(data->env.name + inc)))
			if (ft_strncmp(name, *(data->env.name + inc), ft_strlen(name)) == 0)
				return (*(data->env.value + inc));
		inc++;
	}
	return NULL;
}