/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:32:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 09:38:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_double_quotes(t_data *data, int idx)
{
	push_one_char(data, idx);
	while (*(data->cur.token + idx) != '"')
	{
		if (is_cipher(*(data->cur.token + idx)) == YES)
		{
			
		}
		idx++;
	}
	push_one_char(data, idx);
}
