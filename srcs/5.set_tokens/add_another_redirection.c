/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:37:48 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/15 13:17:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_redirection(t_data *data)
{
	t_red	*clone;
	int		inc;

	inc = 0;
	clone = malloc(sizeof(t_red) * (data->redirect.qty_red + 1));
	while (inc < data->redirect.qty_red)
	{
		(clone + inc)->token = (data->redirect.red + inc)->token;
		(clone + inc)->type = (data->redirect.red + inc)->type;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->type = NO;
	free(data->redirect.red);
	data->redirect.red = clone;
	data->redirect.is_red = YES;
	data->redirect.qty_red++;
}