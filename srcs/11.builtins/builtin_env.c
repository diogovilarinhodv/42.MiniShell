/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:22:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 12:14:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_env(t_data *data)
{
	int		inc;

	inc = 0;
	if (data->env.qty == 0)
	{
		write_str("error, no env vars\n");
		data->exit_status = EXIT_FAILURE;
	}
	set_last_cmd_env(data);
	while (inc < data->env.qty)
	{
		if (ft_strcmp(*(data->env.value + inc), "") != 0)
		{
			write_str(*(data->env.name + inc));
			write_str("=");
			write_str(*(data->env.value + inc));
			write_str("\n");
		}
		inc++;
	}
}
