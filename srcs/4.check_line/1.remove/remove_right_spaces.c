/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_right_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:56:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:05:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	remove_right_spaces(t_data *data)
{
	int		dec;
	char	*clone;

	dec = ft_strlen(data->input.line);
	while (dec > 0)
	{
		if (ft_isspace(*(data->input.line + dec - 1)) == 0)
			break ;
		dec--;
	}
	clone = ft_strndup(data->input.line, dec);
	if (clone == NULL)
		end_program(data, FAIL);
	free(data->input.line);
	data->input.line = clone;
}
