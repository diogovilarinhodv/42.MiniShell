/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_single_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:51:38 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 13:51:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_single_quotes(t_data *data)
{
	push_one_char(data, data->cur.idx_chr);
	while (*(data->cur.token + data->cur.idx_chr) != '\'')
		data->cur.idx_chr++;
	push_one_char(data, data->cur.idx_chr);
}
