/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:46:37 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:12:47 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_input(t_data *data)
{
    if (data->input.line != NULL)
    {
        free(data->input.line);
        data->input.line = NULL;
    }
    data->input.idx = 0;
}
