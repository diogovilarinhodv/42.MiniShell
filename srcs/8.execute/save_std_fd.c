/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_std_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:33:59 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:44:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	save_std_fd(int *stdin_saved, int *stdout_saved)
{
	*stdin_saved = dup(STDIN_FILENO);
	*stdout_saved = dup(STDOUT_FILENO);
}
