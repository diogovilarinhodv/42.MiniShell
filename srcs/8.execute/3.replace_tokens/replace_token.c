/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:28:43 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 10:57:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_token(t_data *data)
{
	data->cur.idx_chr = 0;
	while (*(data->cur.token + data->cur.idx_chr) != '\0')
	{
		if (is_double_quote(data) == YES)
			replace_double_quotes(data);
		else
			data->cur.idx_chr++;
	}
	data->cur.idx_chr = 0;
}
