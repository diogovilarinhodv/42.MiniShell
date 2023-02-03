/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:18:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/29 00:46:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_history(t_data *data)
{
	int	inc;
	
	inc = 0;
	if (data->hist.qty_str == 0)
		data->exit_status = EXIT_FAILURE;
	while (inc < data->hist.qty_str)
	{
		write(STDOUT_FILENO, *(data->hist.str + inc), ft_strlen(*(data->hist.str + inc)));
		write(STDOUT_FILENO, "\n", ft_strlen("\n"));
		inc++;
	}
}
