/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:11:59 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 00:01:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	push_one_char(t_data *data, int inc)
{
	while (*(data->cur.token + inc) != '\0')
	{
		*(data->cur.token + inc) = *(data->cur.token + inc + 1);
		inc++;
	}
}

static void	replace_tokens_quotes(t_data *data)
{
	int		inc;
	int		len;
	char	*new_tkn;

	inc = 0;
	while (*(data->cur.token + inc) != '\0')
	{
		if (*(data->cur.token + inc) == '"')
		{
			push_one_char(data, inc);
			while (*(data->cur.token + inc) != '"')
			{
				if (*(data->cur.token + inc) == '$')
				{
					
				}
				inc++;
			}
			push_one_char(data, inc);
		}
		inc++;
	}
	new_tkn = ft_strdup(data->cur.token);
	free(data->cur.token);
	data->cur.token = new_tkn;
}
/*
static void	replace_tokens_quotes(t_data *data)
{
	if (token_has_tilde(data) == YES)
		replace_home_dir(data);
	if (token_has_single_quotes(data) == YES)
	{
		while (token_has_single_quotes(data) == YES)
			remove_single_quotes(data);
	}
	else if (token_has_double_quotes(data) == YES)
	{
		while (token_has_double_quotes(data) == YES)
			remove_double_quotes(data);
		if (token_has_cipher(data) == YES)
			replace_env_var(data);
	}
	else
		if (token_has_cipher(data) == YES)
			replace_env_var(data);
}
*/

void	replace_tokens(t_data *data)
{
	int	inc_tkn;

	inc_tkn = 0;
	while (inc_tkn < data->cur.cmd->qty_tkn)
	{
		data->cur.token = *(data->cur.cmd->token + inc_tkn);
		replace_tokens_quotes(data);
		*(data->cur.cmd->token + inc_tkn) = data->cur.token;
		inc_tkn++;
	}
	data->cur.token = NULL;
}
