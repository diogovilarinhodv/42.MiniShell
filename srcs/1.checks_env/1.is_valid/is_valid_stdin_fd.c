/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_stdin_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:39:05 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 19:45:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	is_valid_stdin_fd(void)
{
	if (isatty(STDIN_FILENO) == NO)
	{
		write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
}
