/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:39:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:19:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_input_str(t_data *data)
{
	char	*input;

	*(data->input.buf + data->input.buf_idx - 1) = '\0';
	input = ft_strdup(data->input.buf);
	if (input == NULL)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
	return (input);
}
