/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:28:01 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/15 04:17:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_tilde(t_data *data)
{
	if (*(data->cur.token + data->cur.idx_chr) != '~')
		return (NO);
	if (data->cur.idx_chr == 0)
	{
		if (*(data->cur.token + data->cur.idx_chr + 1) == ' ')
			return (YES);
		if (*(data->cur.token + data->cur.idx_chr + 1) == '/')
			return (YES);
		if (*(data->cur.token + data->cur.idx_chr + 1) == '\0')
			return (YES);
	}
	else if (data->cur.idx_chr > 0)
	{
		if (*(data->cur.token + data->cur.idx_chr - 1) == ' '
			&& *(data->cur.token + data->cur.idx_chr + 1) == '/')
			return (YES);
		if (*(data->cur.token + data->cur.idx_chr - 1) == ' '
			&& *(data->cur.token + data->cur.idx_chr + 1) == ' ')
			return (YES);
		if (*(data->cur.token + data->cur.idx_chr - 1) == ' '
			&& *(data->cur.token + data->cur.idx_chr + 1) == '\0')
			return (YES);
	}
	return (NO);
}
