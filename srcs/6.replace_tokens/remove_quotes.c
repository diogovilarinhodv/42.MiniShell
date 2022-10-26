/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:01:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 11:22:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	remove_quotes(t_data *data, int inc)
{
	char	*token;

	token = ft_strndup((*(data->cur.cmd->token + inc) + 1), ft_strlen(*(data->cur.cmd->token + inc)) - 2);
	free(*(data->cur.cmd->token + inc));
	*(data->cur.cmd->token + inc) = token;
}