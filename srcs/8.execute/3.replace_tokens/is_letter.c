/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:15 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 11:04:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_letter(t_data *data)
{
	if (65 <= *(data->cur.token + data->cur.idx_chr) && *(data->cur.token + data->cur.idx_chr) <= 90)
		return (YES);
	if (97 <= *(data->cur.token + data->cur.idx_chr) && *(data->cur.token + data->cur.idx_chr) <= 122)
		return (YES);
	return (NO);
}
