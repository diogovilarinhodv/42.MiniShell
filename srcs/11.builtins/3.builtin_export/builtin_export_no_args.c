/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_no_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:00:12 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 17:00:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	builtin_export_no_args(t_data *data)
{
	int			inc;
	t_env_var	env_sorted;

	inc = 0;
	if (data->env.qty == 0)
	{
		write_str("error, no env vars\n");
		data->exit_status = EXIT_FAILURE;
	}
	set_last_cmd_env(data);
	env_sorted = sort_export_no_args(data);
	while (inc < data->env.qty)
	{
		write_str("declare -x ");
		write_str(*(env_sorted.name + inc));
		write_str("=");
		write_str(*(env_sorted.value + inc));
		write_str("\n");
		inc++;
	}
	free_clone_env(env_sorted);
}
