/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_char_at_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:06:52 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:03:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	has_char_at_end(t_data *data, char c)
{
	int	input_len;

	input_len = ft_strlen(data->input.line);
	if (*(data->input.line + (input_len - 1)) == c)
	{
		write_str("Error: invalid char!\n");
		return (YES);
	}
	return (NO);
}
