/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:38:41 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:11:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	second_check(t_data *data)
{
    if (*data->input.line == '\0')
        return (FAIL);
    return (SUCCESS);
}