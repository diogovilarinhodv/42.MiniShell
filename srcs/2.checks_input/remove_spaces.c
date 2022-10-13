/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:41:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/12 19:28:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	remove_left_spaces(t_data *data)
{
	int     inc;
    char    *clone;

    inc = 0;
    while(*(data->input + inc) != '\0')
    {
        if (ft_isspace(*(data->input + inc)) == 0)
            break;
        inc++;
    }
    clone = ft_strdup(data->input + inc);
    free(data->input);
    data->input = clone;
}

static void	remove_right_spaces(t_data *data)
{
	int     dec;
    char    *clone;

    dec = ft_strlen(data->input);
    while(dec > 0)
    {
        if (ft_isspace(*(data->input + dec - 1)) == 0)
            break;
        dec--;
    }
    clone = ft_strndup(data->input, dec);
    free(data->input);
    data->input = clone;
}

void    remove_spaces(t_data *data)
{
	remove_left_spaces(data);
	remove_right_spaces(data);
}