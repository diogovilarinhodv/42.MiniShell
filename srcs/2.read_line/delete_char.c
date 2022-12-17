/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:01:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 23:09:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	delete_char(t_data *data, char *buf, int *i)
{
	int	qty_to_dlt;

	if (*i == 0 || ft_isascii(buf[*i - 1]))
		qty_to_dlt = 1;
	else
		qty_to_dlt = 2;
	ft_bzero(&buf[*i - qty_to_dlt], BUFSIZ - *i + qty_to_dlt);
	tputs(data->termcaps.del_line, 1, ft_putint);
	tputs(data->termcaps.set_cursor_begin, 1, ft_putint);
	write_prompt(data);
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
}