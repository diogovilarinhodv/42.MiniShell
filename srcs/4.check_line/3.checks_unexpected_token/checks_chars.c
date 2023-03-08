/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:59 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/08 17:49:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	checks_chars(t_data *data)
{
	if (has_char_at_begin(data, '|') == YES)
		return (FAIL);
	if (has_char_at_begin(data, ';') == YES)
		return (FAIL);
	if (has_char_at_end(data, '|') == YES)
		return (FAIL);
	if (has_char_at_end(data, '<') == YES)
		return (FAIL);
	if (has_char_at_end(data, '>') == YES)
		return (FAIL);
	if (has_char_at_end(data, '&') == YES)
		return (FAIL);
	return (SUCCESS);
}
