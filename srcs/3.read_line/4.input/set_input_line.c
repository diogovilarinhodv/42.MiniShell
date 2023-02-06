/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:25:55 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:51:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	set_input_line(t_data *data)
{
	data->input.line = get_input_str(data);
	if (data->input.line == NULL)
		if (*data->input.line == '\0')
			return (FAIL);
	return (SUCCESS);
}
