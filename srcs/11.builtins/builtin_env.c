/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:22:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 21:56:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_env(t_data *data)
{
	int		inc;
	char	*name;
	char	*val;

	inc = 0;
	if (data->env.qty == 0)
		data->exit_status = EXIT_FAILURE;
	set_last_cmd_env(data);
	while (inc < data->env.qty)
	{
		name = *(data->env.name + inc);
		val = *(data->env.value + inc);
		write_str(name);
		write_str("=");
		write_str(val);
		write_str("\n");
		inc++;
	}
}
