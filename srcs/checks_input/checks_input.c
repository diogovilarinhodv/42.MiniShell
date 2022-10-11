/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:24:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/10 14:30:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_input(t_data *data)
{
    int inc;

    inc = 0;
    if (data->input == NULL)
		return (FAIL);
    if (*data->input == NULL)
        return (FAIL);
    skip_initial_spaces(data);
    if (*data->input == '\0')
        return (FAIL);
    if (invalid_input_check(data) == FAIL)
        return (FAIL);
    if (unsupported_char(data) == FAIL)
        return (FAIL);
    return (SUCCESS);
}