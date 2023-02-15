/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:28:36 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/15 16:42:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_termcaps(t_data *data)
{
	if (data->termcaps.backspace != NULL && !IS_LINUX)
		free_str(&data->termcaps.backspace);
}
