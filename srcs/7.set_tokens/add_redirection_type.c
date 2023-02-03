/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:19 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:41:32 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_redirection_type(t_data *data, char *token)
{
	t_red	*cur_red;

	if (data->cur.cmd->qty_red == 0)
		add_first_redirection(data);
	else
		add_another_redirection(data);
	cur_red = (data->cur.cmd->red + data->cur.cmd->qty_red - 1);
	if (ft_strcmp(token, "<") == 0)
		cur_red->type = LEFT_ARROW;
	else if (ft_strcmp(token, ">") == 0)
		cur_red->type = RIGHT_ARROW;
	else if (ft_strcmp(token, ">>") == 0)
		cur_red->type = DOUBLE_RIGHT_ARROW;
	free(token);
}
