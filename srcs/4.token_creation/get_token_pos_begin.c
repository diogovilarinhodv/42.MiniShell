/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_pos_begin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:14:46 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 12:09:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	get_token_pos_begin(t_data *data)
{
	while(ft_isspace(*(data->input.line + data->input.idx)) == 1)
		data->input.idx++;
}