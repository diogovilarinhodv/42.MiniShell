/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:46:37 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:15:34 by dpestana         ###   ########.fr       */
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
	data->input.idx = 0;
}
