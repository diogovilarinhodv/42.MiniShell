/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:40:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/04 14:33:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_input(t_data *data)
{
	if (is_line_empty(data) == YES)
		return (FAIL);
	remove_spaces_bysides(data);
	if (is_line_empty(data) == YES)
		return (FAIL);
	if (checks_unexpected_token(data) == FAIL)
		return (FAIL);
	if (checks_invalid_token(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
