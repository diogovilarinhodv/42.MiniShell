/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:21:29 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:31:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	remove_spaces(t_data *data)
{
	while(*(data->input.line + data->input.idx) != '\0')
    {
        if (ft_isspace(*(data->input.line + data->input.idx)) == 0)
            break;
        data->input.idx++;
    }
}