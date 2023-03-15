/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:28:43 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/15 04:31:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_token(t_data *data)
{
	data->cur.idx_chr = 0;
	while (*(data->cur.token + data->cur.idx_chr) != '\0')
	{
		if (is_tilde(data) == YES)
			replace_tilde(data);
		if (is_single_quote(data) == YES)
			replace_single_quotes(data);
		else if (is_double_quote(data) == YES)
			replace_double_quotes(data);
		else
		{
			if (is_cipher(data) == YES)
				replace_cipher(data);
			else
				data->cur.idx_chr++;
		}
	}
	data->cur.idx_chr = 0;
}
