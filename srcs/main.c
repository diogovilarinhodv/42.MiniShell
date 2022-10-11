/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:07:09 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/11 13:18:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	inicialize(&data, argc, argv, env);
	while (1)
	{
		data.input = readline(BCYN "➜  " BGRN "MiniShell:" RST);
		add_history(data.input);
		//if (check_input(&data) == SUCCESS)
		handle_input(&data);
		freedom(&data, FREEDOM_INPUT);
		inicialize_line(&data);
	}
	end_program(&data);
	return (0);
}
