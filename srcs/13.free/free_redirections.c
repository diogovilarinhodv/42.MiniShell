/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:23:12 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/15 13:28:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_redirections(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->redirect.red != NULL)
	{
		while (inc < data->redirect.qty_red)
		{
			free((data->redirect.red + inc)->token);
			(data->redirect.red + inc)->token = NULL;
			(data->redirect.red + inc)->type = NO;
			inc++;
		}
		free(data->redirect.red);
		data->redirect.red = NULL;
	}
}