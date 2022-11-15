/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:19 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/15 13:19:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_redirection_type(t_data *data, char *token)
{
	if (data->redirect.qty_red == 0)
		add_first_redirection(data);
	else
		add_another_redirection(data);
	if (ft_strncmp(token, "<", 1) == 0)
		(data->redirect.red + data->redirect.qty_red - 1)->type = LEFT_ARROW;
	else if (ft_strncmp(token, ">", 1) == 0)
		(data->redirect.red + data->redirect.qty_red - 1)->type = RIGHT_ARROW;
	else if (ft_strncmp(token, ">>", 2) == 0)
		(data->redirect.red + data->redirect.qty_red - 1)->type = DOUBLE_RIGHT_ARROW;
	free(token);
}