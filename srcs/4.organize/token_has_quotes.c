/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:57:55 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/16 19:48:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	token_has_quotes(t_data *data, int pos_beg, int pos_end)
{
	if (*(data->input + pos_beg) == '"' && *(data->input + pos_end - 1) == '"')
		return (YES);
	if (*(data->input + pos_beg) == '\'' && *(data->input + pos_end - 1) == '\'')
		return (YES);
	return (NO);
}