/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:29 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/31 10:37:47 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_token(t_data *data, char *token)
{
	set_cur(data);
	if (data->cur.cmd->qty_tkn == 0)
		add_first_token(data, token);
	else
		add_another_token(data, token);
	data->cur.cmd->qty_tkn++;
	unset_cur(data);
}