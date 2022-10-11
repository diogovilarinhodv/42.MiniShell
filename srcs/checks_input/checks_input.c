/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:40:44 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/11 15:50:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_input(t_data *data)
{
    if (data->input == NULL)
		return (FAIL);
    if (*data->input == '\0')
        return (FAIL);
    skip_spaces(data);
    if (*data->input == '\0')
        return (FAIL);
	//if (invalid_input_check(data) == FAIL)
	//    return (FAIL);
	// if (unsupported_char(data) == FAIL)
	//   return (FAIL);
    return (SUCCESS);
}