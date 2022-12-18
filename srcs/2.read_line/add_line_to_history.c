/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:27:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 20:21:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_line_to_history(t_data *data)
{
	char	**clone;
	int		inc;

	if (data->hist.str == NULL)
	{
		data->hist.str = malloc(sizeof(char *) * 1);
		*data->hist.str = ft_strdup(data->input.line);
		data->hist.qty_str++;
	}
	else
	{
		inc = 0;
		clone = malloc(sizeof(char *) * (data->hist.qty_str + 1));
		while (inc < data->hist.qty_str)
		{
			*(clone + inc) = *(data->hist.str + inc);
			inc++;
		}
		*(clone + inc) = ft_strdup(data->input.line);;
		free(data->hist.str);
		data->hist.str = clone;
		data->hist.qty_str++;
	}
}
