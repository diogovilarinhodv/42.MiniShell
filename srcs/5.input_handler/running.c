/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:17:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	running(t_data *data)
{
	turn_on_canonical(data);
	initialize_table(data);
	organize(data);
	execute_table(data);
	free_store(data);
}
