/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 22:28:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_token(t_data *data, int *inc, int *pos_beg, int *pos_end)
{
	get_token_pos_begin(data, inc);
	*pos_beg = *inc;
	get_token_pos_end(data, inc);
	*pos_end = *inc;
	if (*(data->input + *inc) != '\0')
		(*inc)++;
}