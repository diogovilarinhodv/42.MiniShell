/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:00:01 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/03 16:06:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	exist_token(t_data *data, int pos_beg, int pos_end)
{
	if (*(data->input.line + data->input.idx) == '\0' && pos_beg == pos_end)
		return (END);
	return (CONTINUE);
}
