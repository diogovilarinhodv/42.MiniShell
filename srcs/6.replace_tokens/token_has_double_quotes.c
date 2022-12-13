/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_double_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:57:55 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:06:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	token_has_double_quotes(t_data *data)
{
	int	len;

	len = ft_strlen(data->cur.token);
	if (*data->cur.token == '"' && *(data->cur.token + len - 1) == '"')
		return (YES);
	return (NO);
}
