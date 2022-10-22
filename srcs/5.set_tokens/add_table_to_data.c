/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_table_to_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:40:27 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 12:57:35 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_table_to_data(t_data *data, t_table *table)
{
	data->store.table = table;
}