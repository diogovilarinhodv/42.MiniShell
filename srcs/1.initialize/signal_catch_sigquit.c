/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catch_sigquit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:13:49 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 23:14:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	catch_sigquit(int signum)
{
	(void)signum;
	printf("Quit: 3\n");
	kill(0, SIGCHLD);
}
