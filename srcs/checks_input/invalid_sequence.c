/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:31:21 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/11 13:04:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int  len_no_spaces(t_data *data)
{
    int inc;
    int len_without_spaces;
    
    inc = 0;
    len_without_spaces = 0;
    while (*(data->input + inc) != '\0')
    {
        if (*(data->input + inc) != ' ')
            len_without_spaces++;
        inc++;
    }
    return (len_without_spaces);
}

static char    *remove_spaces(t_data *data)
{
    int     inc;
    int     idx_input_wo_spaces;
    int     len_without_spaces;
    char    *input_without_spaces;
    
    inc = 0;
    idx_input_wo_spaces = 0;
    len_without_spaces = len_no_spaces(data);
    input_without_spaces = malloc(sizeof(char *) * (len_without_spaces + 1));
    while (*(data->input + inc) != '\0')
    {
        if (*(data->input + inc) != ' ')
        {
            *(input_without_spaces + idx_input_wo_spaces) = *(data->input + inc);
            idx_input_wo_spaces++;
        }
        inc++;
    }
    *(input_without_spaces + idx_input_wo_spaces) = '\0';
    return (input_without_spaces);
}

static void skip_quotes(t_data *data)
{
    int inc;

    inc = 0;
    while (*(data->input + inc) != '\0')
    {
        if (*(data->input + inc) == '"' || *(data->input + inc) == '\'')
        {
            *(data->input + inc) = ' ';
            while (1)
            {
                if (*(data->input + inc) == '"' || *(data->input + inc) == '\'')
                    break;
                *(data->input + inc) = ' ';
                inc++;
            }
            *(data->input + inc) = ' ';
        }
        inc++;
    }
}

int	invalid_sequence(t_data *data, char *c)
{
    int     inc;
    char    *new_input;
    int     inc_c;
    int     len_c;

    inc = 0;
    len_c = ft_strlen(c);
    new_input = remove_spaces(data);
    while (*(new_input + inc) != '\0')
    {
        inc_c = 0;
        while (*(new_input + inc + inc_c) == *(c + inc_c))
            inc_c++;
        if (len_c == inc_c)
            return (FAIL);
        inc++;
    }
    if (new_input != NULL)
    {
        free(new_input);
        new_input = NULL;
    }
    return (SUCCESS);
}