/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:46:37 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:14:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_input(t_data *data)
{
	if (data->input.line != NULL)
	{
		free(data->input.line);
		data->input.line = NULL;
	}
	if (data->input.buf != NULL)
	{
		free(data->input.buf);
		data->input.buf = NULL;
	}
	data->input.idx = 0;
	data->input.buf_idx = 0;
}
