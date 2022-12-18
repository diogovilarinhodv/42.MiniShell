/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_single_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:05:34 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:06:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	token_has_single_quotes(t_data *data)
{
	int	len;

	len = ft_strlen(data->cur.token);
	if (*data->cur.token == '\'' && *(data->cur.token + len - 1) == '\'')
		return (YES);
	return (NO);
}
