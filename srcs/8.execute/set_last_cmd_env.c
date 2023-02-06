/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_cmd_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:45:55 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:52:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_last_cmd_env(t_data *data)
{
	char	*value;

	value = *(data->cur.cmd->token + data->cur.cmd->qty_tkn - 1);
	set_env(data, "_", value);
}
