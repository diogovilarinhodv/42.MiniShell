/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:12:12 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/03 13:46:47 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	invalid_input(t_data *data)
{
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	end_program(data, FAIL);
}
