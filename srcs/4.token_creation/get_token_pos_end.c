/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_end_pos_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:07:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 12:07:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	get_token_pos_end(t_data *data)
{
	while (ft_isspace(*(data->input.line + data->input.idx)) == 0 && *(data->input.line + data->input.idx) != '\0')
		data->input.idx++;
}