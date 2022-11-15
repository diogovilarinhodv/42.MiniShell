/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:37:16 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/15 13:17:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_first_redirection(t_data *data)
{
	data->redirect.red = malloc(sizeof(t_red) * 1);
	data->redirect.red->type = NO;
	data->redirect.red->token = NULL;
	data->redirect.is_red = YES;
	data->redirect.qty_red = 1;
}