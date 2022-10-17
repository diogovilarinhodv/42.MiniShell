/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:00:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 11:05:43 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int token_is_special(t_data *data, int inc)
{
    if (*(*(data->tmp.cmd->token + inc)) == '$')
        return (YES);
    if (*(*(data->tmp.cmd->token + inc)) == '~')
        return (YES);
    return (NO);
}