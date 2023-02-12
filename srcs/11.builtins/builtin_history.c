/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:18:10 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:05:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_history(t_data *data)
{
	int		inc;
	char	*str;

	inc = 0;
	if (data->hist.qty_str == 0)
		data->exit_status = EXIT_FAILURE;
	while (inc < data->hist.qty_str)
	{
		str = *(data->hist.str + inc);
		write_str(str);
		write_str("\n");
		inc++;
	}
}
