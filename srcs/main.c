/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:07:09 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/03 10:25:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	inicialize(&data, argc, argv, env);
	while (1)
		read_input(&data);
	end_program(&data);
	return (0);
}
