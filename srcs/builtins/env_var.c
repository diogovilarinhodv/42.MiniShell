/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:06:45 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:21:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	env_var(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		if (ft_strlen((data->input.cmd + 1)) == ft_strlen(*(data->env.name + inc)))
			if (ft_strncmp((data->input.cmd + 1), *(data->env.name + inc), ft_strlen(data->input.cmd) - 1) == 0)
			{
				printf("%s\n", *(data->env.value + inc));
				break;
			}
		inc++;
	}
}
