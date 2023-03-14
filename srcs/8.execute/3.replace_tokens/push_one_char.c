/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_one_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:29:27 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 10:50:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	push_one_char(t_data *data, int idx)
{
	while (*(data->cur.token + idx) != '\0')
	{
		*(data->cur.token + idx) = *(data->cur.token + idx + 1);
		idx++;
	}
}
