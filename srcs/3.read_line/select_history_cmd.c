/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_history_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:38:16 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:42:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	select_history_cmd(t_data *data)
{
	char	*str;

	str = (data->input.buf + data->input.buf_idx);
	if (has_history(data) == NO)
		ft_bzero(str, BUFSIZ - data->input.buf_idx);
	else if (is_up_arrow(data) == YES)
		execute_up_arrow(data);
	else if (is_down_arrow(data) == YES)
		execute_down_arrow(data);
}
