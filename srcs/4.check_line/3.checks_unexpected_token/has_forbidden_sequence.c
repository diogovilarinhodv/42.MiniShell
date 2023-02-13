/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_forbidden_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:07:25 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 21:17:00 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	has_forbidden_sequence(t_data *data, char *seq)
{
	int		inc;
	char	*str;

	inc = 0;
	str = get_str_without_spaces(data->input.line);
	if (str == NULL)
		end_program(data, FAIL);
	while (*(str + inc) != '\0')
	{
		jump_quotes(str, &inc);
		if (*(data->input.line + inc) == '\0')
			return (SUCCESS);
		if (strncmp((str + inc), seq, ft_strlen(seq)) == 0)
		{
			write_str("Error: invalid sequence!\n");
			free_str(&str);
			return (YES);
		}
		inc++;
	}
	free_str(&str);
	return (NO);
}
