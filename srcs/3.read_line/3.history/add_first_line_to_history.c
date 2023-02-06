/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_line_to_history.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:30:22 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:50:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_first_line_to_history(t_data *data)
{
	data->hist.str = malloc(sizeof(char *) * 1);
	*data->hist.str = ft_strdup(data->input.line);
	data->hist.qty_str++;
}
