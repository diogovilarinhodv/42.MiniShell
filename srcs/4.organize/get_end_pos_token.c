/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_end_pos_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:07:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 13:21:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	get_token_pos_end(t_data *data, int *inc)
{
	while (ft_isspace(*(data->input + *inc)) == 0 && *(data->input + *inc) != '\0')
		(*inc)++;
}