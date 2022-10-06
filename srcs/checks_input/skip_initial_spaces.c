/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_initial_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:30:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/06 10:54:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void    skip_initial_spaces(t_data *data)
{
    int     inc;
    char    *clone;

    inc = 0;
    while((data->input + inc) != NULL)
    {
        if (ft_isspace(*(data->input + inc)) == 0)
            break;
        inc++;
    }
    clone = ft_strdup(data->input + inc);
    free(data->input);
    data->input = clone;
}