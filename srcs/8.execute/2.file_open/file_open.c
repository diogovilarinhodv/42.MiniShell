/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:40:38 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/06 15:22:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	file_open(char *filename, int type, int is_heredoc)
{
	int	fd;

	fd = -1;
	if (type == LEFT_ARROW)
		file_open_left_arrow(filename, type, &fd);
	else if (type == RIGHT_ARROW)
		file_open_right_arrow(filename, type, &fd);
	else if (type == DOUBLE_RIGHT_ARROW)
		file_open_double_right_arrow(filename, type, &fd);
	else if (type == DOUBLE_LEFT_ARROW && is_heredoc == YES)
		file_open_double_left_arrow(filename, type, &fd);
	if (fd != -1)
		close(fd);
	return (fd);
}
