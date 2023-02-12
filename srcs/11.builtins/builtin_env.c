/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:22:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:05:02 by dpestana         ###   ########.fr       */
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
