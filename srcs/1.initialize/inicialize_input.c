/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:46:49 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 19:25:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_input(t_data *data)
{
	data->input.line = NULL;
	data->input.idx = 0;
	data->input.buf = malloc(sizeof(char) * BUFFER_SIZE);
	ft_bzero(data->input.buf, BUFSIZ);
	data->input.buf_idx = 0;
}
