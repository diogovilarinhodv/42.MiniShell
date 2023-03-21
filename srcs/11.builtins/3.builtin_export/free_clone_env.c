/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clone_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:58:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/21 16:59:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	free_clone_env(t_env_var env_sorted)
{
	int	inc;

	inc = 0;
	while (inc < env_sorted.qty)
	{
		free_str((env_sorted.name + inc));
		free_str((env_sorted.value + inc));
		inc++;
	}
	free_str_bd_src(&env_sorted.name);
	free_str_bd_src(&env_sorted.value);
}
