/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:11:59 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:08:35 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_tokens(t_data *data)
{
	int	inc_tkn;

	inc_tkn = 0;
	while (inc_tkn < data->cur.cmd->qty_tkn)
	{
		data->cur.token = *(data->cur.cmd->token + inc_tkn);
		if (token_has_tilde(data) == YES)
			replace_home_dir(data);
		else if (token_has_single_quotes(data) == YES)
			remove_single_quotes(data);
		else
		{
			if (token_has_double_quotes(data) == YES)
				remove_double_quotes(data);
			if (token_has_cipher(data) == YES)
				replace_env_var(data);
		}
		*(data->cur.cmd->token + inc_tkn) = data->cur.token;
		inc_tkn++;
	}
	data->cur.token = NULL;
}
