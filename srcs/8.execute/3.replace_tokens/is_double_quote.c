/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:34:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 10:50:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_double_quote(t_data *data)
{
	if (*(data->cur.token + data->cur.idx_chr) == '"')
		return (YES);
	return (NO);
}
