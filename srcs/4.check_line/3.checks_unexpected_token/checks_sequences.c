/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_sequences.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:28:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 17:07:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	checks_sequences(t_data *data)
{
	if (has_forbidden_sequence(data, ";;") == YES)
		return (FAIL);
	if (has_forbidden_sequence(data, "|;") == YES)
		return (FAIL);
	if (has_forbidden_sequence(data, "&;") == YES)
		return (FAIL);
	if (has_forbidden_sequence(data, ";|") == YES)
		return (FAIL);
	if (has_forbidden_sequence(data, ";&") == YES)
		return (FAIL);
	if (has_forbidden_sequence(data, ">>>") == YES)
		return (FAIL);
	return (SUCCESS);
}
