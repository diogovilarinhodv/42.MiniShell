/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:21:33 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 14:10:54 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int token_has_tilde(t_data *data, int inc)
{
    if (*(*(data->tmp.cmd->token + inc)) == '~')
        return (YES);
    if (*(*(data->tmp.cmd->token + inc)) == '~' && *(*(data->tmp.cmd->token + inc)) == '/')
        return (YES);
    return (NO);
}