/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_invalid_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:05:21 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/04 15:29:05 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	invalid_or(t_data *data, char *seq)
{
	int	inc;

	inc = 0;
	while (*(data->input.line + inc) != '\0')
	{
		jump_quotes(data->input.line, &inc);
		if (*(data->input.line + inc) == '\0')
			return (SUCCESS);
		if (*(data->input.line + inc) == *seq
			&& *(data->input.line + inc + 1) == *seq
			&& *(data->input.line + inc + 2) == *seq)
		{
			write_str("Error: not supported!\n");
			return (FAIL);
		}
		else if (*(data->input.line + inc) == *seq)
			inc++;
		inc++;
	}
	return (SUCCESS);
}

int	checks_invalid_token(t_data *data)
{
	if (invalid_token(data, "*") == FAIL)
		return (FAIL);
	if (invalid_token(data, "\\") == FAIL)
		return (FAIL);
	if (invalid_and(data, "&") == FAIL)
		return (FAIL);
	if (invalid_or(data, "|") == FAIL)
		return (FAIL);
	return (SUCCESS);
}
