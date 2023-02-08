/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_unexpected_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:04:55 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 14:32:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_unexpected_token(t_data *data)
{
	if (has_open_quotes(data) == YES)
		return (FAIL);
	if (checks_chars(data) == FAIL)
		return (FAIL);
	if (checks_sequences(data) == FAIL)
		return (FAIL);
	if (has_spaces(data) == YES)
		return (FAIL);
	return (SUCCESS);
}
