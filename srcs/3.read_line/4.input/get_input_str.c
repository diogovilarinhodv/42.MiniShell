/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:39:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:51:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*get_input_str(t_data *data)
{
	char	*input;

	*(data->input.buf + data->input.buf_idx - 1) = '\0';
	input = ft_strdup(data->input.buf);
	if (input == NULL)
		end_program(data, FAIL);
	return (input);
}
