/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:07:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 13:45:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	checks_env(&data, env);
	initialize(&data, argc, argv, env);
	while (1)
	{
		read_line(&data);
		if (checks_input(&data) == SUCCESS)
			execute(&data);
		free_input(&data);
	}
	end_program(&data, SUCCESS);
	return (0);
}
