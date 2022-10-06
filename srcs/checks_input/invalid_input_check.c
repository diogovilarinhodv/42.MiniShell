/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_input_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:34 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/06 11:39:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	invalid_input_check(t_data *data)
{
    if (invalid_quotes(data) == FAIL)
        return (FAIL);
    if (invalid_initial_char(data, '|') == FAIL)
        return (FAIL);
    if (invalid_initial_char(data, ';') == FAIL)
        return (FAIL);
    if (invalid_end_char(data, '|') == FAIL)
        return (FAIL);
    if (invalid_end_char(data, '<') == FAIL)
        return (FAIL);
    if (invalid_end_char(data, '>') == FAIL)
        return (FAIL);
    if (invalid_end_char(data, '&') == FAIL)
        return (FAIL);
    if (invalid_sequence(data, ";;") == FAIL)
        return (FAIL);
    if (invalid_sequence(data, "|;") == FAIL)
        return (FAIL);
    if (invalid_sequence(data, "&;") == FAIL)
        return (FAIL);
    if (invalid_sequence(data, ";|") == FAIL)
        return (FAIL);
    if (invalid_sequence(data, ";&") == FAIL)
        return (FAIL);
    if (invalid_sequence(data, ">>>") == FAIL)
        return (FAIL);
    if (invalid_sequence(data, ";;") == FAIL)
        return (FAIL);
    if (invalid_space(data, '|') == FAIL)
        return (FAIL);
    if (invalid_space(data, '>') == FAIL)
        return (FAIL);
    return (SUCCESS);
}