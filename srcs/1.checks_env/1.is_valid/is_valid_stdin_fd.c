/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_stdin_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:39:05 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:03:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	is_valid_stdin_fd(void)
{
	if (isatty(STDIN_FILENO) == NO)
	{
		write_str("Error\n");
		exit(1);
	}
}
