/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:22:33 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 13:44:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int     is_quote(t_data *data, int *inc)
{
    if (*(data->input + *inc) == '"' || *(data->input + *inc) == '\'')
        return (YES);
    return (NO);
}