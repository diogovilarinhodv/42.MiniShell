/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_pos_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:25:40 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 13:47:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void     get_quote_pos_end(t_data *data)
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