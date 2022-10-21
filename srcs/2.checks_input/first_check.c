/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:36:49 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:13:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	first_check(t_data *data)
{
    if (data->input.line == NULL)
		return (FAIL);
    if (*data->input.line == '\0')
        return (FAIL);
	 return (SUCCESS);
}