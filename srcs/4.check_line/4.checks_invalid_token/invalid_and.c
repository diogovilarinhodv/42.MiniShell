/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:08:38 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 17:28:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	invalid_and(t_data *data, char *seq)
{
	int	inc;

	inc = 0;
	while (*(data->input.line + inc) != '\0')
	{
		jump_quotes(data->input.line, &inc);
		if (*(data->input.line + inc) == '\0')
			return (SUCCESS);
		if (*(data->input.line + inc) == *seq && *(data->input.line + inc + 1) != *seq)
		{
			write(STDOUT_FILENO, "Error: not supported!\n", ft_strlen("Error: not supported!\n"));
			return (FAIL);
		}
		else if (*(data->input.line + inc) == *seq)
			inc++;
		inc++;
	}
	return (SUCCESS);
}
