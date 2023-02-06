/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_left_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:56:27 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:04:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	remove_left_spaces(t_data *data)
{
	int		inc;
	char	*clone;

	inc = 0;
	while (*(data->input.line + inc) != '\0')
	{
		if (ft_isspace(*(data->input.line + inc)) == 0)
			break ;
		inc++;
	}
	clone = ft_strdup(data->input.line + inc);
	if (clone == NULL)
		end_program(data, FAIL);
	free(data->input.line);
	data->input.line = clone;
}
