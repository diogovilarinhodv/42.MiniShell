/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:52:52 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/06 10:59:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	invalid_quotes(t_data *data)
{
    int inc;
    int single_quote;
    int double_quote;

    inc = 0;
    single_quote = 0;
    double_quote = 0;
    while ((data->input + inc) != NULL)
    {
        if (*(data->input + inc) == '"' && single_quote == 0)
            double_quote = !double_quote;
        else if (*(data->input + inc) == '\'' && double_quote == 0)
            single_quote = !single_quote;
        inc++;
    }
    if (single_quote == 1 || double_quote == 1)
        return (FAIL);
    return (SUCCESS);
}