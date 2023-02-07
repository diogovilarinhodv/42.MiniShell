/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:38:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/07 08:40:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	exit_table(t_data *data, int inc_tbl)
{
	if ((data->store.table + inc_tbl)->delimiter == DELIMITER_AND)
		if (data->exit_status != EXIT_SUCCESS)
			return (YES);
	if ((data->store.table + inc_tbl)->delimiter == DELIMITER_OR)
		if (data->exit_status == EXIT_SUCCESS)
			return (YES);
	return (NO);
}
