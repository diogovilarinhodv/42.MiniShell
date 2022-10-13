/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:36:49 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/12 19:39:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	first_check(t_data *data)
{
    if (data->input == NULL)
		return (FAIL);
    if (*data->input == '\0')
        return (FAIL);
	 return (SUCCESS);
}