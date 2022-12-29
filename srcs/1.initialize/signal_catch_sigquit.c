/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catch_sigquit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:13:49 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/20 13:09:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	catch_sigquit(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	kill(0, SIGCHLD);
}
