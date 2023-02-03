/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:22:40 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/29 00:47:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_env(t_data *data)
{
	int	inc;

	inc = 0;
	if (data->env.qty == 0)
		data->exit_status = EXIT_FAILURE;
	while (inc < data->env.qty)
	{
		write(STDOUT_FILENO, *(data->env.name + inc), ft_strlen(*(data->env.name + inc)));
		write(STDOUT_FILENO, "=", ft_strlen("="));
		write(STDOUT_FILENO, *(data->env.value + inc), ft_strlen(*(data->env.value + inc)));
		write(STDOUT_FILENO, "\n", ft_strlen("\n"));
		inc++;
	}
}
