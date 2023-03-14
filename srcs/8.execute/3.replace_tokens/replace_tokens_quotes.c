/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tokens_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:28:43 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 09:35:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_tokens_quotes(t_data *data)
{
	int		idx;
	int		len;
	char	*new_tkn;

	idx = 0;
	while (*(data->cur.token + idx) != '\0')
	{
		if (is_double_quote(*(data->cur.token + idx)) == YES)
			replace_double_quotes(data, idx);
		idx++;
	}
	new_tkn = ft_strdup(data->cur.token);
	free(data->cur.token);
	data->cur.token = new_tkn;
}
