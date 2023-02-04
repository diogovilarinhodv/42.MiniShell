/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst_alloc_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:43:36 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:09:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_env_lst_alloc_value(t_data *data)
{
	data->env.value = malloc(sizeof(char **) * data->env.qty);
	if (data->env.value == NULL)
		end_program(data, FAIL);
}
