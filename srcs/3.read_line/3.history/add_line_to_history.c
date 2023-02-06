/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:20:06 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:52:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_line_to_history(t_data *data)
{
	if (data->hist.str == NULL)
		add_first_line_to_history(data);
	else
		add_other_line_to_history(data);
}
