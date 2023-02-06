/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:43:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:44:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	close_std_fd(int *stdin_saved, int *stdout_saved)
{
	dup2(*stdin_saved, STDIN_FILENO);
	dup2(*stdout_saved, STDOUT_FILENO);
	close(*stdin_saved);
	close(*stdout_saved);
}
