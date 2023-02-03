/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:22:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 17:48:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_env(t_data *data)
{
	int		inc;
	char	*name;
	char	*val;

	inc = 0;
	if (data->env.qty == 0)
		data->exit_status = EXIT_FAILURE;
	while (inc < data->env.qty)
	{
		name = *(data->env.name + inc);
		val = *(data->env.value + inc);
		write(STDOUT_FILENO, name, ft_strlen(name));
		write(STDOUT_FILENO, "=", ft_strlen("="));
		write(STDOUT_FILENO, val, ft_strlen(val));
		write(STDOUT_FILENO, "\n", ft_strlen("\n"));
		inc++;
	}
}
