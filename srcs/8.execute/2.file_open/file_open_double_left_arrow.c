/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open_double_left_arrow.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:25 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 14:44:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	file_open_double_left_arrow(char *filename, int type, int *fd)
{
	*fd = open("tmp_file", O_RDONLY, 0666);
	if (*fd != -1)
		dup2(*fd, STDIN_FILENO);
}
