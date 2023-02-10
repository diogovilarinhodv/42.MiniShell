/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:20:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 15:35:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_redirects(t_data *data)
{
	int	inc_red;

	inc_red = 0;
	while (inc_red < data->cur.cmd->qty_red)
	{
		data->cur.token = (data->cur.cmd->red + inc_red)->token;
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
		(data->cur.cmd->red + inc_red)->token = data->cur.token;
		inc_red++;
	}
	data->cur.token = NULL;
}
