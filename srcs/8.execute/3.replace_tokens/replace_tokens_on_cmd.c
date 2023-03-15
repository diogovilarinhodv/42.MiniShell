/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tokens_on_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:11:59 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/15 04:29:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_tokens_on_cmd(t_data *data)
{
	int	inc_tkn;

	inc_tkn = 0;
	while (inc_tkn < data->cur.cmd->qty_tkn)
	{
		data->cur.token = *(data->cur.cmd->token + inc_tkn);
		replace_token(data);
		*(data->cur.cmd->token + inc_tkn) = data->cur.token;
		inc_tkn++;
	}
	data->cur.token = NULL;
}
