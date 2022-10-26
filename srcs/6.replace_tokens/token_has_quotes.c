/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:57:55 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 11:21:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	token_has_quotes(t_data *data, int inc)
{
	int	len;

	len = ft_strlen(*(data->cur.cmd->token + inc));
	if (*(*(data->cur.cmd->token + inc)) == '"' && *(*(data->cur.cmd->token + inc) + len - 1) == '"')
		return (YES);
	if (*(*(data->cur.cmd->token + inc)) == '\'' && *(*(data->cur.cmd->token + inc) + len - 1) == '\'')
		return (YES);
	return (NO);
}