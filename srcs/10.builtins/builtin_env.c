/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:22:40 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/05 17:39:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_env(t_data *data)
{
	int	inc;

	inc = 0;
	while (inc < data->env.qty)
	{
		printf("%s=%s\n", *(data->env.name + inc), *(data->env.value + inc));
		inc++;
	}
}
