/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:48:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/28 06:57:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_echo(t_data *data)
{
	int		inc;
	int		newline;
	char	*env_var;
	int		can_space;

	inc = 0;
	newline = 1;
	env_var = NULL;
	can_space = 1;
	if (data->input.qty_args > 1)
		if (ft_strncmp(*data->input.args, "-n", ft_strlen(*data->input.args)) == 0)
		{
			inc++;
			newline = 0;
		}
	while (inc < data->input.qty_args)
	{
		if (**(data->input.args + inc) == '$')
		{
			env_var = get_env_value(data, (*(data->input.args + inc) + 1));
			if (env_var != NULL)
				printf("%s", env_var);
			else
				can_space = 0;
		}
		else
		{
			printf("%s", *(data->input.args + inc));
			can_space = 1;
		}
		if (inc + 1 < data->input.qty_args && can_space == 1)
			printf(" ");
		inc++;
	}
	if (newline == 1)
		printf("\n");
}
