/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:11:59 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 14:15:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_tokens(t_data *data)
{
    int     inc;

    inc = 0;
    while(inc < data->tmp.cmd->qty_tkn)
    {
        if (token_has_cipher(data, inc) == YES)
            replace_env_var(data, inc);
        else if (token_has_tilde(data, inc) == YES)
            replace_home_dir(data, inc);
	    else if (token_has_quotes(data, inc) == YES)
		    remove_quotes(data, inc);
        inc++;
    }
}