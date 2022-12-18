/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tkn_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:58:19 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 02:58:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*new_tkn_replace(t_data *data)
{
	int		inc_chr;
	int		pos;
	char	*new_token;

	inc_chr = 0;
	pos = 0;
	new_token = NULL;
	while (*(data->cur.token + inc_chr) != '\0')
	{
		if (*(data->cur.token + inc_chr) == '$')
		{
			new_token = tkn_replace(data, &inc_chr, pos, new_token);
			pos = inc_chr;
			inc_chr--;
		}
		inc_chr++;
	}
	if (pos != inc_chr)
		new_token = append_tkn_replace(data, pos, new_token);
	return (new_token);
}
