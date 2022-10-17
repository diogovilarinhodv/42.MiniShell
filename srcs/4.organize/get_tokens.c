/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 14:09:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	get_tokens(t_data *data, int *inc, int *pos_beg, int *pos_end)
{
	get_token_pos_begin(data, inc);
	*pos_beg = *inc;
	if (is_quote(data, inc) == YES)
		get_pos_end_quote(data, inc);
	else
		get_token_pos_end(data, inc);
	*pos_end = *inc;
	if (*(data->input + *inc) != '\0')
		(*inc)++;
}