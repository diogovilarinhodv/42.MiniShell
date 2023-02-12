/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:08:11 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:03:54 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	invalid_token(t_data *data, char *tkn)
{
	int	inc;
	int	has;

	inc = 0;
	if (tkn == NULL)
		end_program(data, FAIL);
	if (*tkn == '\0')
		end_program(data, FAIL);
	while (*(data->input.line + inc) != '\0')
	{
		jump_quotes(data->input.line, &inc);
		if (*(data->input.line + inc) == '\0')
			return (SUCCESS);
		has = ft_strncmp((data->input.line + inc), tkn, ft_strlen(tkn));
		if (has == 0)
		{
			write_str("Error: not supported!\n");
			return (FAIL);
		}
		inc++;
	}
	return (SUCCESS);
}
