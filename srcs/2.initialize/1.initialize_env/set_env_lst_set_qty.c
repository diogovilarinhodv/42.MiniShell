/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst_set_qty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:40:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:36:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_env_lst_set_qty(t_data *data, char **env)
{
	data->env.qty = 0;
	while (*(env + data->env.qty) != NULL)
		data->env.qty++;
	if (data->env.qty == 0)
		end_program(data, FAIL);
}
