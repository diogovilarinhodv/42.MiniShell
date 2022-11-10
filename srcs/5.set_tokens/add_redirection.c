/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:19 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/10 11:56:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	first_redirection(t_data *data)
{
	data->redirect = malloc(sizeof(t_redirect) * 1);
	data->redirect->destiny = NULL;
	data->redirect->type = NULL;
	data->redirect->is = YES;
	data->redirect->qty = 1;
}

static void	another_redirection(t_data *data)
{
	t_redirect	*clone;
	int			inc;

	inc = 0;
	clone = malloc(sizeof(t_redirect) * (data->redirect->qty + 1));
	while (inc < data->redirect->qty)
	{
		*(clone + inc) = *(data->redirect + inc);
		inc++;
	}
	*(clone + inc)->destiny = NULL;
	*(clone + inc)->type = NULL;
	clone->is = YES;
	clone->qty = data->redirect->qty + 1;
}

void	add_redirection(t_data *data, char *token)
{
	if (data->redirect == NULL)
		first_redirection(data);
	else
		another_redirection(data);
	if (ft_strncmp(token, "<", 1) == 0)
		(data->redirect + data->redirect->qty - 1)->type = ft_strdup("<");
	else if (ft_strncmp(token, ">", 1) == 0)
		(data->redirect + data->redirect->qty - 1)->type = ft_strdup(">");
	else if (ft_strncmp(token, ">>", 2) == 0)
		(data->redirect + data->redirect->qty - 1)->type = ft_strdup(">>");
	(data->redirect + data->redirect->qty - 1)->is = YES;
	free(token);
}