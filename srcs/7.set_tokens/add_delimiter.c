/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delimiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:19 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/18 19:03:47 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_delimiter(t_data *data, char *token)
{
	if (*token == ';')
		data->cur.table->delimiter = DELIMITER_NULL;
	else if (*token == '|' && *(token + 1) == '|')
		data->cur.table->delimiter = DELIMITER_OR;
	else if (*token == '&' && *(token + 1) == '&')
		data->cur.table->delimiter = DELIMITER_AND;
}
