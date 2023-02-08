/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_open_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:05:52 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 17:09:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	has_open_quotes(t_data *data)
{
	int	single_quotes_open;
	int	double_quotes_open;
	int	inc;

	single_quotes_open = 0;
	double_quotes_open = 0;
	inc = 0;
	while (*(data->input.line + inc) != '\0')
	{
		if (*(data->input.line + inc) == '"' && single_quotes_open == 0)
			double_quotes_open = !double_quotes_open;
		else if (*(data->input.line + inc) == '\'' && double_quotes_open == 0)
			single_quotes_open = !single_quotes_open;
		inc++;
	}
	if (double_quotes_open || single_quotes_open)
	{
		write(STDOUT_FILENO, "Error: open quotes!\n", ft_strlen("Error: open quotes!\n"));
		return (YES);
	}
	return (NO);
}
