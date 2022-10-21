/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:07:09 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:08:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	inicialize(&data, argc, argv, env);
	while (1)
	{
		data.input.line = readline(BCYN "➜  " BGRN "MiniShell:" RST);
		add_history(data.input.line);
		if (checks_input(&data) == SUCCESS)
			handle_input(&data);
		free_input(&data);
	}
	end_program(&data, SUCCESS);
	return (0);
}
