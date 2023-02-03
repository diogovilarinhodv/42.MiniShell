/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catch_sigquit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:13:49 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 19:31:04 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	catch_sigquit(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	kill(0, SIGCHLD);
}
