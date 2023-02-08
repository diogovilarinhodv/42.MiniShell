/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:29:39 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 17:11:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	has_spaces(t_data *data)
{
	if (space_between_char(data, '|') == YES)
		return (FAIL);
	if (space_between_char(data, '>') == YES)
		return (FAIL);
	return (SUCCESS);
}
