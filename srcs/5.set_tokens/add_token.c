/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:29 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/10 11:51:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	set_token_redirect(t_data *data, char *token)
{
	if (data->redirect != NULL)
	{
		if ((data->redirect + data->redirect->qty - 1)->is == YES)
		{
			(data->redirect + data->redirect->qty - 1)->destiny = token;
			(data->redirect + data->redirect->qty - 1)->is = NO;
		}
	}
}

void	add_token(t_data *data, char *token)
{
	set_cur(data);
	if (data->cur.cmd->qty_tkn == 0)
		add_first_token(data, token);
	else
		add_another_token(data, token);
	data->cur.cmd->qty_tkn++;
	unset_cur(data);
	set_token_redirect(data, token);
}