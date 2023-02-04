/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:46:49 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 17:12:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_input(t_data *data)
{
	data->input.line = NULL;
	data->input.idx = 0;
	data->input.buf = malloc(sizeof(char) * BUFSIZ);
	ft_bzero(data->input.buf, BUFSIZ);
	data->input.buf_idx = 0;
}
