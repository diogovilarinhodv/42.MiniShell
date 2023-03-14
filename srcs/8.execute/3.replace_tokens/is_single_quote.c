/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_single_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:49:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 13:50:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_single_quote(t_data *data)
{
	if (*(data->cur.token + data->cur.idx_chr) == '\'')
		return (YES);
	return (NO);
}
