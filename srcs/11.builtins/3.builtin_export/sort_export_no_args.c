/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export_no_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:02:14 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 17:13:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

t_env_var	sort_export_no_args(t_data *data)
{
	int			hold_pos;
	int			search_pos;
	t_env_var	env_sorted;

	hold_pos = 0;
	env_sorted = clone_env(data);
	while (hold_pos < env_sorted.qty - 1)
	{
		search_pos = hold_pos + 1;
		while (search_pos < env_sorted.qty)
		{
			env_sorted = set_env_sorted(env_sorted, hold_pos, search_pos);
			search_pos++;
		}
		hold_pos++;
	}
	return (env_sorted);
}
