/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_unsupported_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:05:21 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 17:02:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_invalid_token(t_data *data)
{
	if (invalid_token(data, "<<") == FAIL)
		return (FAIL);
	if (invalid_token(data, "*") == FAIL)
		return (FAIL);
	if (invalid_token(data, "\\") == FAIL)
		return (FAIL);
	if (invalid_and(data, "&") == FAIL)
		return (FAIL);
	return (SUCCESS);
}
