/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:15:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/16 18:11:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	void	add_first_arg(t_data *data, char *arg)
{
	data->lst_cmd->args = malloc(sizeof(char **) * data->lst_cmd->qty_args);
	*data->lst_cmd->args = arg;
}

static	void	add_other_arg(t_data *data, char *arg)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * data->lst_cmd->qty_args);
	while (inc < data->lst_cmd->qty_args - 1)
	{
		*(clone + inc) = *(data->lst_cmd->args + inc);
		inc++;
	}
	*(clone + inc) = arg;
	free(data->lst_cmd->args);
	data->lst_cmd->args = clone;
}

void	set_args(t_data *data, int pos_beg, int pos_end)
{
	char	*arg;

	data->lst_cmd->qty_args++;
	arg = ft_substr(data->line, pos_beg, pos_end - pos_beg);
	if (data->lst_cmd->args == NULL)
		add_first_arg(data, arg);
	else
		add_other_arg(data, arg);
}
