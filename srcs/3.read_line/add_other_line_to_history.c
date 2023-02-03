/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_other_line_to_history.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:31:16 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:32:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_other_line_to_history(t_data *data)
{
	char	**clone;
	int		inc;
	char	*str;

	str = *(data->hist.str + data->hist.qty_str - 1);
	if (ft_strcmp(str, data->input.line) == 0)
		return ;
	inc = 0;
	clone = malloc(sizeof(char *) * (data->hist.qty_str + 1));
	while (inc < data->hist.qty_str)
	{
		*(clone + inc) = *(data->hist.str + inc);
		inc++;
	}
	*(clone + inc) = ft_strdup(data->input.line);
	free(data->hist.str);
	data->hist.str = clone;
	data->hist.qty_str++;
}
