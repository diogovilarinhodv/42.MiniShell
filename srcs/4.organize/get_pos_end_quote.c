/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_end_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:25:40 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 12:06:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void     get_pos_end_quote(t_data *data)
{
    if (*(data->input.line + data->input.idx) == '"')
    {
        data->input.idx++;
        while (*(data->input.line + data->input.idx) != '"')
            data->input.idx++;
        data->input.idx++;
    }
    else if(*(data->input.line + data->input.idx) == '\'')
    {
        data->input.idx++;
        while (*(data->input.line + data->input.idx) != '\'')
            data->input.idx++;
        data->input.idx++;
    }
}