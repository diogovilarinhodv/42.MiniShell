/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open_left_arrow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:34:47 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 14:44:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	file_open_left_arrow(char *filename, int type, int *fd)
{
	*fd = open(filename, O_RDONLY, 0);
	if (*fd != -1)
		dup2(*fd, STDIN_FILENO);
}
