/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_cipher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:00:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 12:21:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int token_has_cipher(t_data *data, int inc)
{
    if (*(*(data->tmp.cmd->token + inc)) == '$')
        return (YES);
    return (NO);
}