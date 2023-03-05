/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open_double_right_arrow.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:39:23 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 14:44:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	file_open_double_right_arrow(char *filename, int type, int *fd)
{
	*fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (*fd != -1)
		dup2(*fd, STDOUT_FILENO);
}
