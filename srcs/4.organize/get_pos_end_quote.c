/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_end_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:25:40 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 13:45:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void     get_pos_end_quote(t_data *data, int *inc)
{
    if (*(data->input + *inc) == '"')
    {
        (*inc)++;
        while (*(data->input + *inc) != '"')
            (*inc)++;
        (*inc)++;
    }
    else if(*(data->input + *inc) == '\'')
    {
        (*inc)++;
        while (*(data->input + *inc) != '\'')
            (*inc)++;
        (*inc)++;
    }
}