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
	data->input.args = malloc(sizeof(char **) * data->input.qty_args);
	*data->input.args = arg;
}

static	void	add_other_arg(t_data *data, char *arg)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * data->input.qty_args);
	while (inc < data->input.qty_args - 1)
	{
		*(clone + inc) = *(data->input.args + inc);
		inc++;
	}
	*(clone + inc) = arg;
	free(data->input.args);
	data->input.args = clone;
}

void	set_args(t_data *data, int pos_beg, int pos_end)
{
	char	*arg;

	data->input.qty_args++;
	arg = ft_substr(data->input.line, pos_beg, pos_end - pos_beg);
	if (data->input.args == NULL)
		add_first_arg(data, arg);
	else
		add_other_arg(data, arg);
}
