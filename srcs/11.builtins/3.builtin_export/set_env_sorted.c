/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:08:47 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 17:10:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

t_env_var	set_env_sorted(t_env_var env_sorted, int hold_pos, int search_pos)
{
	char	*tmp;
	char	*name_hold_pos;
	char	*name_search_pos;

	name_hold_pos = *(env_sorted.name + hold_pos);
	name_search_pos = *(env_sorted.name + search_pos);
	if (ft_strcmp(name_hold_pos, name_search_pos) > 0)
	{
		tmp = *(env_sorted.name + hold_pos);
		*(env_sorted.name + hold_pos) = *(env_sorted.name + search_pos);
		*(env_sorted.name + search_pos) = tmp;
		tmp = *(env_sorted.value + hold_pos);
		*(env_sorted.value + hold_pos) = *(env_sorted.value + search_pos);
		*(env_sorted.value + search_pos) = tmp;
	}
	return (env_sorted);
}
