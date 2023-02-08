/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_between_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:07:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 16:40:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	space_between_char(t_data *data, char c)
{
	int	inc;

	inc = 0;
	while (*(data->input.line + inc) == '\0')
	{
		jump_quotes(data->input.line, &inc);
		if (*(data->input.line + inc) == c && *(data->input.line + inc + 1) == ' ')
		{
			inc++;
			while (*(data->input.line + inc) == ' ')
				inc++;
			if (*(data->input.line + inc) == c)
			{
				write(STDOUT_FILENO, "Error: invalid space!\n", ft_strlen("Error: invalid space!\n"));
				return (YES);
			}
		}
		if (*(data->input.line + inc) != '\0')
			inc++;
	}
	return (NO);
}
