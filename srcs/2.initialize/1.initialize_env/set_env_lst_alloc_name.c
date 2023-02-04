/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst_alloc_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:42:45 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:09:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	set_env_lst_alloc_name(t_data *data)
{
	data->env.name = malloc(sizeof(char **) * data->env.qty);
	if (data->env.name == NULL)
		end_program(data, FAIL);
}
