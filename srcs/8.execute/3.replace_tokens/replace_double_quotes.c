/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:32:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 11:31:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_double_quotes(t_data *data)
{
	push_one_char(data, data->cur.idx_chr);
	while (*(data->cur.token + data->cur.idx_chr) != '"')
	{
		if (is_cipher(data) == YES)
			replace_cipher(data);
		else
			data->cur.idx_chr++;
	}
	push_one_char(data, data->cur.idx_chr);
}
