/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_one_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:29:27 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 09:29:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	push_one_char(t_data *data, int inc)
{
	while (*(data->cur.token + inc) != '\0')
	{
		*(data->cur.token + inc) = *(data->cur.token + inc + 1);
		inc++;
	}
}
