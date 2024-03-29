/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_char_at_begin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:06:23 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:03:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	has_char_at_begin(t_data *data, char c)
{
	if (*data->input.line == c)
	{
		write_str("Error: invalid char!\n");
		return (YES);
	}
	return (NO);
}
